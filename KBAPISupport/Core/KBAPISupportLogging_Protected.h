//
//  KBAPISupportLogging_Protected.h
//  KBAPISupport
//
//  Created by Kirill Bystrov on 4/1/16.
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

#if __has_include (<KBAPISupport/KBAPISupport+Logging.h>)
#	import <KBAPISupport/KBAPISupport+Logging.h>
#	define KBLOG_MACRO(lvl, fmt, args...) ([[KBLogger sharedLogger] logWithLevel:lvl file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__ message:fmt, ##args])
#	define KBLOGE(fmt, args...) KBLOG_MACRO (KBLogLevelError, fmt, ##args)
#	define KBLOGW(fmt, args...) KBLOG_MACRO (KBLogLevelWarning, fmt, ##args)
#	define KBLOGI(fmt, args...) KBLOG_MACRO (KBLogLevelInfo, fmt, ##args)
#	define KBLOGD(fmt, args...) KBLOG_MACRO (KBLogLevelDebug, fmt, ##args)
#else
#	define KBLOGE(...)
#	define KBLOGW(...)
#	define KBLOGI(...)
#	define KBLOGD(...)
#endif
