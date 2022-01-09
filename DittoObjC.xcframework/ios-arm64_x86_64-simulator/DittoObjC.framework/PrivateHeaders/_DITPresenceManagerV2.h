//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//


#import <Foundation/Foundation.h>

@class _DITDittoHandleWrapper;
@class DITPeersObserverV2;
@class _DITWeakWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface _DITPresenceManagerV2 : NSObject
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) dispatch_queue_t internalQueue;
@property (nonatomic, readonly) NSMutableArray<_DITWeakWrapper *> *observers;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;
- (void)presenceUpdate:(NSString *)json targetObservers:(NSArray<_DITWeakWrapper *> *)observers;
- (DITPeersObserverV2 *)observePeers:(void (^)(NSString *))callback queue:(dispatch_queue_t)queue;
- (void)scheduleFlush;
@end

NS_ASSUME_NONNULL_END
