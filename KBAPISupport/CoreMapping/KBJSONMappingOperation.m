//
//  KBJSONMappingOperation.m
//  KBAPISupport
//
//  Created by Kirill Bystrov on 3/30/16.
//  Copyright © 2016 Kirill byss Bystrov. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#if __has_include (<KBAPISupport/KBAPISupport+JSON.h>)

#import "KBJSONMappingOperation.h"
#import "KBOperation_Protected.h"

#import "KBObject.h"

@interface KBJSONMappingOperation () {
	id <KBObject> _result;
}

@end

@implementation KBJSONMappingOperation

- (void) main {
	id JSONObject = self.JSONObject;
	if (JSONObject) {
		Class expectedClass = self.expectedClass;
		if ([expectedClass conformsToProtocol:@protocol (KBObject)]) {
			_result = [expectedClass objectFromJSON:JSONObject];
		}

		if (!_result) {
			Class errorClass = self.errorClass;
			NSError *mappedError = nil;
			if ([errorClass conformsToProtocol:@protocol (KBObject)]) {
				mappedError = [errorClass objectFromJSON:JSONObject];
			}
			
			if ([mappedError isKindOfClass:[NSError class]]) {
				self.error = mappedError;
			} else {
				self.error = [NSError errorWithDomain:@"KBAPIConnection" code:-1 userInfo:@{NSLocalizedDescriptionKey: [NSString stringWithFormat:@"Cannot build %@ from JSON object.", self.expectedClass]}];
			}
		}
	}
	
	[super main];
}

- (id)result {
	return _result;
}

@end

#endif