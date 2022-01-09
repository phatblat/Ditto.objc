//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDittoDelegate.h>
#import <DittoObjC/DITTransportConfig.h>
#import <DittoObjC/DITLogLevel.h>

#import <Foundation/Foundation.h>

@class DITAuthenticator;
@class DITIdentity;
@class DITPeersObserver;
@class DITPeersObserverV2;
@class DITRemotePeer;
@class DITStore;
@class DITTransportDiagnostics;

NS_ASSUME_NONNULL_BEGIN

/**
 The entrypoint to the Ditto SDK.

 For a `DITDitto` instance to continue to connect to other devices it must be kept in scope.
 */
@interface DITDitto : NSObject

/**
 Configure a custom identifier for the current device.

 When using `observePeers`, each remote peer is represented by a short UTF-8 "device name".

 By default this will be a truncated version of the device's hostname. It does not need to be unique
 among peers.

 Configure the device name before calling `startSync`. If it is too long it may be truncated.
 */
@property (nonatomic) NSString *deviceName;

/**
 Provides access to the SDK's store functionality.
 */
@property (atomic, readonly) DITStore *store;

/**
 Provides access to authentication information and methods for logging on to
 Ditto Cloud.
 */
@property (nonatomic, nullable, readonly) DITAuthenticator *auth;

/**
 A flag indicating whether or not the SDK has been activated with a valid
 license token.
 */
@property (nonatomic, readonly, getter=isActivated) BOOL activated;

/**
 A flag indicating whether or not the SDK has been activated with a valid
 license token.
 */
- (BOOL)activated __deprecated_msg("use `isActivated` getter instead.");

/**
 The site ID that the instance of `DITDitto` is using as part of its identity.
 */
@property (nonatomic, readonly) uint64_t siteID;

/**
 An optional delegate that will be called with SDK lifecycle information if defined.
 */
@property (nonatomic, weak) id<DITDittoDelegate> delegate;

/**
 The dispatch queue that will be used to deliver delegate events. Defaults to the main queue.
 */
@property (nonatomic) dispatch_queue_t delegateEventQueue;

/**
Enable or disable history tracking. Default is `NO`. History Tracking is
**experimental** and shouldn't be used in production.
*/
@property (nonatomic, getter = isHistoryTrackingEnabled) BOOL historyTrackingEnabled;

/**
 Initializes a new `DITDitto`.
 This will initialize an instance of `DITDitto` with the default configuration.
 */
- (instancetype)init;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity;

/**
 Initializes a new `DITDitto`.

 @param identity Provide the identity of the entity that is interacting with Ditto.
 @param directory The directory that will be used to persist Ditto data.
 */
- (instancetype)initWithIdentity:(DITIdentity *)identity
            persistenceDirectory:(nullable NSURL *)directory;

/**
 Starts the network transports. Ditto will connect to other devices and sync with them where
 appropriate.

 By default Ditto will enable all peer-to-peer transport types. On iOS this means Bluetooth,
 WiFi and AWDL. The network configuration can be customized using the `setTransportConfig`
 method.
 */
- (void)startSync __deprecated_msg("use `tryStartSync` instead.");

/**
 Starts the network transports. Ditto will connect to other devices and sync with them where
 appropriate.

 By default Ditto will enable all peer-to-peer transport types. On iOS this means Bluetooth,
 WiFi and AWDL. The network configuration can be customized using the `setTransportConfig`
 method.

 You must have activated Ditto with a successful call to `setLicenseToken` before starting sync.

 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return `YES` if sync was successfully started. `NO` otherwise.
 */
- (BOOL)tryStartSync:(NSError *_Nullable __autoreleasing *)error;

/**
 Stops all network transports.

 You may continue to use the database locally but no data will sync to or from other devices.
 */
- (void)stopSync;

/**
 Assign a new transports configuration. By default peer-to-peer transports (Bluetooth, WiFi and
 AWDL) are enabled.

 You may use this method to alter the configuration at any time. Sync will not begin until
 `startSync` is called.
 */
- (void)setTransportConfig:(DITTransportConfig *)config;

/**
 Activate a `DITDitto` instance by setting an access license. You cannot meaningfully interact
 with a `DITDitto` instance before you have activated it.

 @param license The license to activate the `DITDitto` instance with, which you can find on the Ditto portal (https://portal.ditto.live).
 */
- (void)setAccessLicense:(NSString *)license __deprecated_msg("use `setLicenseToken` instead.");

/**
 Activate a `DITDitto` instance by setting a license token. You cannot meaningfully interact
 with a `DITDitto` instance before you have activated it.

 @param licenseToken The license token to activate the `DITDitto` instance with, which you can find on the Ditto portal (https://portal.ditto.live).
 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return `YES` if the license token was successfully set and the `DITDitto` instance is now
 activated for sync. `NO` otherwise.
 */
- (BOOL)setLicenseToken:(NSString *)licenseToken error:(NSError *_Nullable __autoreleasing *)error;

/**
 Request bulk status information about the transports.

 This is mostly intended for statistical or debugging purposes.

 @param error On input, a pointer to an error object. If an error occurs, this pointer
 is set to an actual error object containing the error information. You may specify nil for this
 parameter if you do not want the error information.

 @return An instance of `DITTransportDiagnostics` or `nil` if there was an error.
 */
- (nullable DITTransportDiagnostics *)transportDiagnostics:(NSError **)error;

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are required. A newly
 registered observer will have a peers update delivered to it immediately. From then on it will be
 invoked repeatedly when Ditto devices come and go, or the active connections to them change.
 */
- (DITPeersObserver *)observePeers:(void (^)(NSArray<DITRemotePeer *> *))callback;

/**
 Request information about Ditto peers in range of this device.

 This method returns an observer which should be held as long as updates are required. A newly
 registered observer will have a peers update delivered to it immediately. From then on it will be
 invoked repeatedly when Ditto devices come and go, or the active connections to them change.
 */
- (DITPeersObserverV2 *)observePeersV2:(void (^)(NSString *))callback;

/**
 Returns a string identifying the version of the Ditto SDK.
 */
- (NSString *)sdkVersion;

/**
 The default location of Ditto data files when no persistence directory is specified.
 */
+ (NSURL *)defaultDittoDirectory:(NSFileManager *)fileManager;

/**
 Removes all sync metadata for any remote peers which aren't currently connected. This
 method shouldn't usually be called. Manually running garbage collection often will
 result in slower sync times. Ditto automatically runs a garbage a collection process
 in the background at optimal times.

 Manually running garbage collection is typically only useful during testing if large
 amounts of data are being generated. Alternatively, if an entire data set is to be
 evicted and it's clear that maintaining this metadata isn't necessary, then garbage
 collection could be run after evicting the old data.
 */
- (void)runGarbageCollection;


@end

NS_ASSUME_NONNULL_END
