//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITPeerToPeer.h>

#import <DittoObjC/DITMutableAWDLConfig.h>
#import <DittoObjC/DITMutableBluetoothLEConfig.h>
#import <DittoObjC/DITMutableLANConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutablePeerToPeer : DITPeerToPeer

@property (nonatomic, readwrite, strong) DITMutableBluetoothLEConfig *bluetoothLe;
@property (nonatomic, readwrite, strong) DITMutableLANConfig *lan;
@property (nonatomic, readwrite, strong) DITMutableAWDLConfig *awdl;

@end

NS_ASSUME_NONNULL_END
