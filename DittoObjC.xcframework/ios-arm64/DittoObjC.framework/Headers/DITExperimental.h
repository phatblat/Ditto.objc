//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DITBus.h"

NS_ASSUME_NONNULL_BEGIN

@class DITDitto;

/**
 Upcoming SDK features made available for prototyping.
 
 Experimental functionality should not be used in production applications
 as it may be changed or removed at any time, and may not have the same
 security features.
 */
@interface DITExperimental : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (DITBus *)busFor:(DITDitto *)ditto;

@end

NS_ASSUME_NONNULL_END
