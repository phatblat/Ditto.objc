//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An address uniquely representing another device on the Ditto network.
 */
@interface DITAddress : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (BOOL)isEqualToAddress:(DITAddress *)address;

@end

NS_ASSUME_NONNULL_END
