//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITBluetoothLEConfig.h>
#import <DittoObjC/DITLANConfig.h>
#import <DittoObjC/DITAWDLConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Configuration of peer-to-peer transports, which are able to discover and connect to peers on their own.

 For more information refer to the documentation for DITTransportConfig.
 */
@interface DITPeerToPeer : NSObject<NSCopying, NSMutableCopying> {
    @protected DITBluetoothLEConfig *_bluetoothLe;
    @protected DITLANConfig *_lan;
    @protected DITAWDLConfig *_awdl;
}

@property (nonatomic, readonly) DITBluetoothLEConfig *bluetoothLe;
@property (nonatomic, readonly) DITLANConfig *lan;
@property (nonatomic, readonly) DITAWDLConfig *awdl;

- (instancetype)initWithDITPeerToPeer:(DITPeerToPeer *)peerToPeer;
- (instancetype)initWithBluetoothLe:(DITBluetoothLEConfig *)bluetoothLe
                             lan:(DITLANConfig *)lan
                             awdl:(DITAWDLConfig *)awdl NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
