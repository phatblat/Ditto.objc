//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITLANConfig : NSObject<NSCopying, NSMutableCopying> {
    @protected BOOL _enabled;
    @protected BOOL _mDNSEnabled;
    @protected BOOL _multicastEnabled;
}

@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;
@property (nonatomic, readonly, getter = ismDNSEnabled) BOOL mDNSEnabled;
@property (nonatomic, readonly, getter = isMulticastEnabled) BOOL multicastEnabled;

- (instancetype)initWithDITLANConfig:(DITLANConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled
    mDNSEnabled:(BOOL)mDNSEnabled
    multicastEnabled:(BOOL)multicastEnabled NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToDITLANConfig:(DITLANConfig *)config;

@end

NS_ASSUME_NONNULL_END
