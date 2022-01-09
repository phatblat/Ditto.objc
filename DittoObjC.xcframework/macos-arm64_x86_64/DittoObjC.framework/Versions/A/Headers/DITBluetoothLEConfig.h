//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITBluetoothLEConfig : NSObject<NSCopying, NSMutableCopying> {
    @protected BOOL _enabled;
}

@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;

- (instancetype)initWithDITBluetoothLEConfig:(DITBluetoothLEConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToDITBluetoothLEConfig:(DITBluetoothLEConfig *)config;

@end

NS_ASSUME_NONNULL_END
