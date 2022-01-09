//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITAWDLConfig : NSObject<NSCopying, NSMutableCopying> {
    @protected BOOL _enabled;
}

@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;

- (instancetype)initWithDITAWDLConfig:(DITAWDLConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToDITAWDLConfig:(DITAWDLConfig *)config;

@end

NS_ASSUME_NONNULL_END
