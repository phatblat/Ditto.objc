//
//  Copyright © 2019 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "dittoffi.h"

NS_ASSUME_NONNULL_BEGIN

#define DittoLogError(args...) _Log(C_LOG_LEVEL_ERROR, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DittoLogWarning(args...) _Log(C_LOG_LEVEL_WARNING, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DittoLogInfo(args...) _Log(C_LOG_LEVEL_INFO, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DittoLogDebug(args...) _Log(C_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);
#define DittoLogVerbose(args...) _Log(C_LOG_LEVEL_VERBOSE, __FILE__, __LINE__, __PRETTY_FUNCTION__, args);

@interface Log : NSObject

void _Log(CLogLevel_t logLevel, const char *file, int lineNumber, const char *funcName, NSString *format, ...) NS_FORMAT_FUNCTION(5,6);

@end

NS_ASSUME_NONNULL_END
