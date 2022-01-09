//
// Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DITBus;
@class DITBusMessage;

@protocol DITBusDelegate <NSObject>

- (void)ditBus:(DITBus *)bus didReceiveMessage:(DITBusMessage *)message;

@end

