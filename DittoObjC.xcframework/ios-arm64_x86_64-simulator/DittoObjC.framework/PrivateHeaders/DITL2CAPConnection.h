//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>

@class DITTransportHandleWrapper;
@protocol DITL2CAPConnectionDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface DITL2CAPConnection : NSObject <NSStreamDelegate>

- (instancetype)initWithChannel:(CBL2CAPChannel *)channel handle:(DITTransportHandleWrapper *)handle isServer:(BOOL)isServer uuid:(NSUUID *)uuid runLoop:(NSRunLoop *)runLoop;
- (int)sendDataDirect:(NSData *)data;
- (int)readDataDirect:(uint8_t *)buffer maxLength:(NSUInteger)len;
- (void)close;

@property (nonatomic, weak) NSObject<DITL2CAPConnectionDelegate> *delegate;
@property (nonatomic, strong, readonly) NSRunLoop *runLoop;
@property (nonatomic, strong) CBL2CAPChannel *channel;
@property (nonatomic, weak) DITTransportHandleWrapper *handle;
@property (nonatomic) BOOL isServer;
@property (nonatomic, copy) NSUUID *uuid;
@property (nonatomic) BOOL isFailed;

@end

NS_ASSUME_NONNULL_END
