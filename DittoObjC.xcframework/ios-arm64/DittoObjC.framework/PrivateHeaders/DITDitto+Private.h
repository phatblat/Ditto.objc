//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDitto.h>

@class _DITDittoHandleWrapper;
@class _DITValidityListener;
@class _DITPresenceManagerV1;
@class _DITPresenceManagerV2;

@class DITTransportHandleWrapper;
@class DITAWDLClientPlatform;
@class DITAWDLServerPlatform;
@class DITBluetoothPlatform;
@class DITMDNSPlatform;
@class _DITStatus;
@class DITBus;

@class DITBluetoothLEConfig;
@class DITLANConfig;
@class DITAWDLConfig;
@class DITTCPListenConfig;
@class DITHTTPListenConfig;
@class DITIdentityProvider;
@class DITGlobalConfig;

@class _DITHistory;

NS_ASSUME_NONNULL_BEGIN

@interface DITDitto ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) _DITPresenceManagerV1 *presenceV1;
@property (nonatomic, readonly) _DITPresenceManagerV2 *presenceV2;
@property (nonatomic) BOOL transportConditionCallbackRegistered;

@property (copy, nonatomic) DITTransportConfig *transportConfig;
@property (nonatomic) BOOL syncActive;

@property (nonatomic, nullable) DITMDNSPlatform *mdnsPlatform;
@property (nonatomic, nullable) DITBluetoothPlatform *bluetoothPlatform;
@property (nonatomic, nullable) DITAWDLClientPlatform *awdlClientPlatform;
@property (nonatomic, nullable) DITAWDLServerPlatform *awdlServerPlatform;
@property (nonatomic, nullable)
    NSMutableDictionary<NSString *, DITTransportHandleWrapper *> *staticTcpClients;
@property (nonatomic, nullable)
    NSMutableDictionary<NSString *, DITTransportHandleWrapper *> *staticWebClients;
@property (nonatomic, nullable) DITIdentityProvider *identityProvider;

@property (nonatomic) _DITStatus *status;
@property (nonatomic) DITBus *bus;

@property (nonatomic, readonly) _DITValidityListener *validityListener;

/// We can start WebSocket client transports
@property (nonatomic) BOOL webIdentityValid;
/// We can start TCP and P2P transports
@property (nonatomic) BOOL x509IdentityValid;

@property (nonatomic, readonly) _DITHistory *history;

- (void)initSdkVersion;

- (void)applyTransportConfig:(DITTransportConfig *)config fromPreviousConfig:(DITTransportConfig *)oldConfig;
- (void)applyTransportGlobalConfig:(DITGlobalConfig *)config fromPreviousConfig:(DITGlobalConfig *)oldConfig;
- (void)applyAuthValidityChangedWeb:(BOOL)web oldWeb:(BOOL)oldWeb x509:(BOOL)x509 oldX509:(BOOL)oldX509;
- (void)startBluetoothLETransport:(DITBluetoothLEConfig *)config;
- (void)stopBluetoothLETransport;
- (void)startLANTransport:(DITLANConfig *)config shouldStartServer:(BOOL)shouldStartServer;
- (void)stopLANTransportStoppingServer:(BOOL)shouldStopServer;
- (void)startAWDLTransport:(DITAWDLConfig *)config;
- (void)stopAWDLTransport;
- (void)startTCPListen:(DITTCPListenConfig *)config;
- (void)stopTCPListen;
- (void)startHTTPListen:(DITHTTPListenConfig *)config;
- (void)stopHTTPListen;
- (void)startTCPConnect:(NSString *)addr;
- (void)stopTCPConnect:(NSString *)addr;
- (void)startWSConnect:(NSString *)url;
- (void)stopWSConnect:(NSString *)url;
- (void)startAuthServer:(DITHTTPListenConfig *)http;
- (void)stopAuthServer;
- (void)validityUpdatedWithWebValid:(BOOL)webValid x509Valid:(BOOL)x509Valid;

@end

NS_ASSUME_NONNULL_END
