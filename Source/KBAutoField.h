//
//  KBAutoField.h
//  KBAPISupport
//
//  Created by Kirill byss Bystrov on 06.12.12.
//  Copyright (c) 2012 Kirill byss Bystrov. All rights reserved.
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

#if !__has_feature(objc_arc)

#import <Foundation/Foundation.h>

#ifndef IMPORTED_FROM_KBAPISUPPORT_H
#	warning Please #import "KBAPISupport.h".
#endif

#if KBAPISUPPORT_XML
@class GDataXMLElement;
#endif

@protocol KBAutoField <NSObject>
@required

- (NSString *) fieldName;
- (void) setFieldName: (NSString *) fieldName;
#if KBAPISUPPORT_XML
- (BOOL) isAttribute;
- (void) setIsAttribute: (BOOL) isAttribute;
#endif

#if KBAPISUPPORT_JSON
- (BOOL) setFieldInObject: (id) object fromJSON: (id) JSON;
#endif
#if KBAPISUPPORT_XML
- (BOOL) setFieldInObject: (id) object fromXML: (GDataXMLElement *) XML;
#endif

@optional
- (NSString *) sourceFieldName;
- (void) setSourceFieldName: (NSString *) sourceFieldName;

@end

///////////////////////// Some standart field types /////////////////////////

@interface KBAutoFieldBase: NSObject <KBAutoField>

#if KBAPISUPPORT_XML
@property (nonatomic, assign) BOOL isAttribute;
#endif
@property (nonatomic, retain) NSString *fieldName;
@property (nonatomic, retain) NSString *sourceFieldName;

@end

@interface KBAutoIntegerField: KBAutoFieldBase

@property (nonatomic, assign) BOOL isUnsigned;

@end

@interface KBAutoStringField: KBAutoFieldBase

@end

@interface KBAutoObjectField: KBAutoFieldBase

@property (nonatomic, retain) Class objectClass;

@end

#endif // !__has_feature(objc_arc)