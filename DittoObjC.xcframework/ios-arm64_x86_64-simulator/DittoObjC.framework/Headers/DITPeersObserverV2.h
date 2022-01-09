//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A token returned by calling `observePeersV2` on a `DITDitto` object.

 Retain this object to continue receiving callback updates.
 */
@interface DITPeersObserverV2 : NSObject

- (void)stop;

@end

NS_ASSUME_NONNULL_END
