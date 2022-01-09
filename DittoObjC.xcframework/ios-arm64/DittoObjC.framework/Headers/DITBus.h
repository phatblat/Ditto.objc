//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITBusDelegate.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class _DITDittoHandleWrapper;
@class DITAddress;

@interface DITBus : NSObject

@property (nonatomic, nullable) id<DITBusDelegate> delegate;
@property (nonatomic) dispatch_queue_t delegateEventQueue;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDittoHandle:(_DITDittoHandleWrapper *)dittoHandleWrapper NS_DESIGNATED_INITIALIZER;
- (void)sendMessageWithData:(NSData *)data toAddress:(DITAddress *)address;

@end

NS_ASSUME_NONNULL_END
