//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A token returned by calling `observePeers` on a `DITDitto` object.

 Retain this object to continue receiving callback updates.
 */
@interface DITPeersObserver : NSObject

- (void)stop;

@end

NS_ASSUME_NONNULL_END
