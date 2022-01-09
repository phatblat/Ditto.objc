//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DITAuthenticationDelegate;

/**
 The identity types you can use with DittoObjC.

 The various identity configurations that you can use when initializing a
 `DITDitto` instance.

 - Development: (Deprecated - use OfflinePlayground instead) Develop
   peer-to-peer apps with no cloud connection. This mode offers no security and
   must only be used for development.
 - OfflinePlayground: Develop peer-to-peer apps with no cloud connection. This
   mode offers no security and must only be used for development.
 - Online: (Deprecated - use OnlineWithAuthentication instead) Run Ditto in
   secure production mode, logging on to Ditto Cloud or on on-premises
   authentication server. User permissions are centrally managed.
 - OnlineWithAuthentication: Run Ditto in secure production mode, logging on to
   Ditto Cloud or on on-premises authentication server. User permissions are
   centrally managed.
 - OnlinePlayground: Test a Ditto Cloud app without authentication ("Playground
   mode"). This mode offers no security and must only be used for development.
 - SharedKey: A mode where any device is trusted provided they know the secret
   key. This is a simplistic authentication model normally only suitable for
   private apps where users and devices are both trusted.
 - Manual: A manually-provided certificate identity. This accepts a
   base64-encoded bundle.
 */
typedef NS_ENUM(NSUInteger, DITIdentityType) {
    DittoDevelopmentIdentity = 0,
    DittoOfflinePlaygroundIdentity = 0,
    DittoOnlineIdentity,
    DittoOnlineWithAuthenticationIdentity,
    DittoOnlinePlaygroundIdentity,
    DittoSharedKeyIdentity,
    DittoManualIdentity,
};

/**
 Used to identify a given peer in your network. In practice a peer may be a
 user, a device, or it might be some other entity in your system.
 */
@interface DITIdentity : NSObject

/**
 The type of the identity.
 */
@property (nonatomic, readonly) enum DITIdentityType type;

/**
 The app ID.

 Use this to ensure that connections between devices are only established if
 they share the same app ID.

 Note that this will not be set for all identity types.
 */
@property (nonatomic, readonly, nullable) NSString *appID;

/**
 The site ID.

 Use this to identity different users or devices. Site IDs are persisted between
 sessions.

 Site IDs should be unique and not reused by different users or devices.

 Note that this will not be set to a meaningful value for all identity types.
 `0` will represent an unset value.
 */
@property (nonatomic, readonly) uint64_t siteID;

/**
 If true, sync with Ditto Cloud will be auto-configured.

 Note that this will not be set to a meaningful value for all identity types.
 `false` will represent an unset value.
 */
@property (nonatomic, readonly) BOOL enableDittoCloudSync;

/**
 A base64 encoded DER representation of a private key, which is shared between
 devices for a single app.

 Note that this will not be set for all identity types.
 */
@property (nonatomic, readonly, nullable) NSURL *customAuthURL;

/**
 A base64 encoded DER representation of a private key, which is shared between
 devices for a single app.

 Note that this will not be set for all identity types.
 */
@property (nonatomic, readonly, nullable) NSString *sharedKey;

/**
 A base64 encoded string representation of a certificate bundle.

 Note that this will not be set for all identity types.
 */
@property (nonatomic, readonly, nullable) NSString *certificateConfig;

/**
 Creates an OfflinePlayground identity suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @return The default OfflinePlayground identity.
 */
- (instancetype)init;

// MARK: Development identity inits

/**
 Creates a development identity suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @return The default development identity.
 */
- (instancetype)initDevelopment __deprecated_msg("use `initOfflinePlayground` instead.");

/**
 Creates a development identity with the provided site ID and the default app
 ID. The identity created will be suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @param siteID the site ID of the peer.

 @return A development identity using the default app ID and the provided site
 ID.
 */
- (instancetype)initDevelopmentWithSiteID:(uint64_t)siteID __deprecated_msg("use `initOfflinePlayground` instead.");

/**
 Creates a development identity with the provided app ID and a random site ID.
 The identity created will be suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.

 @return A development identity using the provided app ID and a random site ID.
 */
- (instancetype)initDevelopmentWithAppID:(NSString *)appID __deprecated_msg("use `initOfflinePlayground` instead.");

/**
 Creates a development identity with the provided app ID and a random site ID.
 The identity created will be suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param directory The directory that will be used to persist Ditto data.

 @return A development identity using the provided app ID and a random site ID.
 */
- (instancetype)initDevelopmentWithAppID:(NSString *)appID persistenceDirectory:(nullable NSURL *)directory __deprecated_msg("use `initOfflinePlayground` instead.");

/**
 Creates a development identity with the provided app ID and provided site ID.
 The identity created will be suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @param appID an optional UUID identifying this app registration on the Ditto
 portal, which can be found at https://portal.ditto.live.
 @param siteID the site ID of the peer.

 @return A development identity using either the provided app ID or the default
 one, and the provided site ID.
 */
- (instancetype)initDevelopmentWithAppID:(nullable NSString *)appID
                                  siteID:(uint64_t)siteID __deprecated_msg("use `initOfflinePlayground` instead.");

/**
 Creates a development identity with the provided app ID and provided site ID.
 The identity created will be suitable to develop peer-to-peer apps with no
 cloud connection. This mode offers no security and must only be used for
 development.

 @param appID an optional UUID identifying this app registration on the Ditto
 portal, which can be found at https://portal.ditto.live.
 @param siteID the site ID of the peer.
 @param directory The directory that will be used to persist Ditto data.

 @return A development identity using either the provided app ID or the default
 one, and the provided site ID.
 */
- (instancetype)initDevelopmentWithAppID:(nullable NSString *)appID
                                  siteID:(uint64_t)siteID
                    persistenceDirectory:(nullable NSURL *)directory __deprecated_msg("use `initOfflinePlayground` instead.");

// MARK: OfflinePlayground identity inits

/**
 Creates an OfflinePlayground identity suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @return The default OfflinePlayground identity.
 */
- (instancetype)initOfflinePlayground;

/**
 Creates an OfflinePlayground identity with the provided site ID and the default
 app ID. The identity created will be suitable to develop peer-to-peer apps with
 no cloud connection. This mode offers no security and must only be used for
 development.

 @param siteID the site ID of the peer.

 @return An OfflinePlayground identity using the default app ID and the provided
 site ID.
 */
- (instancetype)initOfflinePlaygroundWithSiteID:(uint64_t)siteID;

/**
 Creates an OfflinePlayground identity with the provided app ID and a random
 site ID. The identity created will be suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.

 @return An OfflinePlayground identity using the provided app ID and a random
 site ID.
 */
- (instancetype)initOfflinePlaygroundWithAppID:(NSString *)appID;

/**
 Creates an OfflinePlayground identity with the provided app ID and a random
 site ID. The identity created will be suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param directory The directory that will be used to persist Ditto data.

 @return An OfflinePlayground identity using the provided app ID and a random
 site ID.
 */
- (instancetype)initOfflinePlaygroundWithAppID:(NSString *)appID
                          persistenceDirectory:(nullable NSURL *)directory;

/**
 Creates an OfflinePlayground identity with the provided app ID and provided
 site ID. The identity created will be suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @param appID an optional UUID identifying this app registration on the Ditto
 portal, which can be found at https://portal.ditto.live.
 @param siteID the site ID of the peer.

 @return An OfflinePlayground identity using either the provided app ID or the
 default one, and the provided site ID.
 */
- (instancetype)initOfflinePlaygroundWithAppID:(nullable NSString *)appID
                                        siteID:(uint64_t)siteID;

/**
 Creates an OfflinePlayground identity with the provided app ID and provided
 site ID. The identity created will be suitable to develop peer-to-peer apps
 with no cloud connection. This mode offers no security and must only be used
 for development.

 @param appID an optional UUID identifying this app registration on the Ditto
 portal, which can be found at https://portal.ditto.live.
 @param siteID the site ID of the peer.
 @param directory The directory that will be used to persist Ditto data.

 @return An OfflinePlayground identity using either the provided app ID or the
 default one, and the provided site ID.
 */
- (instancetype)initOfflinePlaygroundWithAppID:(nullable NSString *)appID
                                        siteID:(uint64_t)siteID
                          persistenceDirectory:(nullable NSURL *)directory;

// MARK: Online identity inits

/**
 Creates an Online identity.

 Online identities should be used when running Ditto in secure production mode,
 logging on to Ditto Cloud, or using an on-premises authentication server. User
 permissions are centrally managed. Sync will not work until a successful login
 has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 callback. If you want to configure a custom auth URL or specify that you don't
 want cloud sync to be used then use one of the other `initOnline`-prefixed
 methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter found in the other `initOnline`-prefixed
 methods. If `true` (default), a suitable wss:// URL will be added to the
 `TransportConfig`. To prevent cloud sync, or to specify your own URL later,
 pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, use the appropriate
 `initOnline`-prefixed method and pass a custom HTTPS base URL as the
 `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re)authentication.

 @return An Online identity suitable for a production Ditto deployment.
 */
- (instancetype)initOnlineWithAppID:(NSString *)appID
             authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate __deprecated_msg("use `initOnlineWithAuthenticationWithAppID` instead.");

/**
 Creates an Online identity.

 Online identities should be used when running Ditto in secure production mode,
 logging on to Ditto Cloud, or using an on-premises authentication server. User
 permissions are centrally managed. Sync will not work until a successful login
 has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 callback. If you don't want/need to provide a value for `enableDittoCloudSync`
 then use one of the other `initOnline`-prefixed methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter. If `true` (default), a suitable wss://
 URL will be added to the `TransportConfig`. To prevent cloud sync, or to
 specify your own URL later, pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, pass a custom HTTPS
 base URL as the `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re-)authentication.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.

 @return An Online identity suitable for a production Ditto deployment.
 */
- (instancetype)initOnlineWithAppID:(NSString *)appID
             authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate
               enableDittoCloudSync:(BOOL)enableDittoCloudSync __deprecated_msg("use `initOnlineWithAuthenticationWithAppID` instead.");

/**
 Creates an Online identity.

 Online identities should be used when running Ditto in secure production mode,
 logging on to Ditto Cloud, or using an on-premises authentication server. User
 permissions are centrally managed. Sync will not work until a successful login
 has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 delegate. If you don't want/need to provide a value for `enableDittoCloudSync`
 or `customAuthURL` then use one of the other `initOnline`-prefixed methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter. If `true` (default), a suitable wss://
 URL will be added to the `TransportConfig`. To prevent cloud sync, or to
 specify your own URL later, pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, pass a custom HTTPS
 base URL as the `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re-)authentication.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.
 @param customAuthURL if specified, use a custom authentication service instead
 of Ditto Cloud.
 @param directory The directory that will be used to persist Ditto data.

 @return An Online identity suitable for a production Ditto deployment.
 */
- (instancetype)initOnlineWithAppID:(NSString *)appID
             authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate
               enableDittoCloudSync:(BOOL)enableDittoCloudSync
                      customAuthURL:(nullable NSURL *)customAuthURL
               persistenceDirectory:(nullable NSURL *)directory __deprecated_msg("use `initOnlineWithAuthenticationWithAppID` instead.");

// MARK: OnlineWithAuthentication identity inits

/**
 Creates an OnlineWithAuthentication identity.

 OnlineWithAuthentication identities should be used when running Ditto in secure
 production mode, logging on to Ditto Cloud, or using an on-premises
 authentication server. User permissions are centrally managed. Sync will not
 work until a successful login has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 callback. If you want to configure a custom auth URL or specify that you don't
 want cloud sync to be used then use one of the other
 `initOnlineWithAuthentication`-prefixed methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter found in the other
 `initOnlineWithAuthentication`-prefixed methods. If `true` (default), a
 suitable wss:// URL will be added to the `TransportConfig`. To prevent cloud
 sync, or to specify your own URL later, pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, use the appropriate
 `initOnlineWithAuthentication`-prefixed method and pass a custom HTTPS base URL
 as the `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re)authentication.

 @return An OnlineWithAuthentication identity suitable for a production Ditto
 deployment.
 */
- (instancetype)initOnlineWithAuthenticationWithAppID:(NSString *)appID
                               authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate;

/**
 Creates an OnlineWithAuthentication identity.

 OnlineWithAuthentication identities should be used when running Ditto in secure
 production mode, logging on to Ditto Cloud, or using an on-premises
 authentication server. User permissions are centrally managed. Sync will not
 work until a successful login has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 callback. If you don't want/need to provide a value for `enableDittoCloudSync`
 then use one of the other `initOnlineWithAuthentication`-prefixed methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter. If `true` (default), a suitable wss://
 URL will be added to the `TransportConfig`. To prevent cloud sync, or to
 specify your own URL later, pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, pass a custom HTTPS
 base URL as the `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re-)authentication.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.

 @return An OnlineWithAuthentication identity suitable for a production Ditto
 deployment.
 */
- (instancetype)initOnlineWithAuthenticationWithAppID:(NSString *)appID
                               authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate
                                 enableDittoCloudSync:(BOOL)enableDittoCloudSync;

/**
 Creates an OnlineWithAuthentication identity.

 OnlineWithAuthentication identities should be used when running Ditto in secure
 production mode, logging on to Ditto Cloud, or using an on-premises
 authentication server. User permissions are centrally managed. Sync will not
 work until a successful login has occurred.

 The only required configuration is the application's UUID, which can be found
 on the Ditto portal where the app is registered, and an authentication
 delegate. If you don't want/need to provide a value for `enableDittoCloudSync`
 or `customAuthURL` then use one of the other
 `initOnlineWithAuthentication`-prefixed methods.

 By default cloud sync is enabled. This means the SDK will sync to a Big Peer in
 Ditto's cloud when an internet connection is available. This is controlled by
 the `enableDittoCloudSync` parameter. If `true` (default), a suitable wss://
 URL will be added to the `TransportConfig`. To prevent cloud sync, or to
 specify your own URL later, pass `false`.

 Authentication requests are handled by Ditto's cloud by default, configured in
 the portal at https://portal.ditto.live.

 To use a different or on-premises authentication service, pass a custom HTTPS
 base URL as the `customAuthURL` parameter.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param authenticationDelegate a handler for when Ditto requires
 (re-)authentication.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.
 @param customAuthURL if specified, use a custom authentication service instead
 of Ditto Cloud.
 @param directory The directory that will be used to persist Ditto data.

 @return An OnlineWithAuthentication identity suitable for a production Ditto
 deployment.
 */
- (instancetype)initOnlineWithAuthenticationWithAppID:(NSString *)appID
                               authenticationDelegate:(id<DITAuthenticationDelegate>)authenticationDelegate
                                 enableDittoCloudSync:(BOOL)enableDittoCloudSync
                                        customAuthURL:(nullable NSURL *)customAuthURL
                                 persistenceDirectory:(nullable NSURL *)directory;

// MARK: OnlinePlayground identity inits

/**
 Creates an OnlinePlayground identity.

 OnlinePlayground identities should be used when you want to test a Ditto Cloud
 app without authentication ("Playground mode"). This mode offers no security
 and must only be used for development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.

 @return An Online identity suitable when using Ditto in development.
 */
- (instancetype)initOnlinePlaygroundWithAppID:(NSString *)appID;

/**
 Creates an OnlinePlayground identity.

 OnlinePlayground identities should be used when you want to test a Ditto Cloud
 app without authentication ("Playground mode"). This mode offers no security
 and must only be used for development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.

 @return An OnlinePlayground identity suitable when using Ditto in development.
 */
- (instancetype)initOnlinePlaygroundWithAppID:(NSString *)appID
                         enableDittoCloudSync:(BOOL)enableDittoCloudSync;

/**
 Creates an OnlinePlayground identity.

 OnlinePlayground identities should be used when you want to test a Ditto Cloud
 app without authentication ("Playground mode"). This mode offers no security
 and must only be used for development.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param enableDittoCloudSync if true, auto-configure sync with Ditto Cloud.
 @param directory The directory that will be used to persist Ditto data.

 @return An OnlinePlayground identity suitable when using Ditto in development.
 */
- (instancetype)initOnlinePlaygroundWithAppID:(NSString *)appID
                         enableDittoCloudSync:(BOOL)enableDittoCloudSync
                         persistenceDirectory:(nullable NSURL *)directory;

// MARK: SharedKey identity inits

/**
 Creates a shared key identity with the provided app ID, site ID and shared key.

 Identities created using this init should be used where any device is trusted
 provided they know the shared key. This is a simplistic authentication model
 normally only suitable for private apps where users and devices are both
 trusted. In this mode, any string may be used as the app ID.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param sharedKey a base64-encoded DER private key. Refer to Ditto documentation
 for details about generating shared keys.
 @param siteID the site ID of the peer.

 @return A shared key identity
 */
- (instancetype)initSharedKeyWithAppID:(NSString *)appID
                             sharedKey:(NSString *)sharedKey
                                siteID:(uint64_t)siteID;

/**
 Creates a shared key identity with the provided app ID, site ID and shared key.

 Identities created using this init should be used where any device is trusted
 provided they know the shared key. This is a simplistic authentication model
 normally only suitable for private apps where users and devices are both
 trusted. In this mode, any string may be used as the app ID.

 @param appID a UUID identifying this app registration on the Ditto portal,
 which can be found at https://portal.ditto.live.
 @param sharedKey a base64-encoded DER private key. Refer to Ditto documentation
 for details about generating shared keys.
 @param siteID the site ID of the peer.
 @param directory The directory that will be used to persist Ditto data.

 @return A shared key identity
 */
- (instancetype)initSharedKeyWithAppID:(NSString *)appID
                             sharedKey:(NSString *)sharedKey
                                siteID:(uint64_t)siteID
                  persistenceDirectory:(nullable NSURL *)directory;

// MARK: Manual identity inits

/**
 Creates a Manual identity using the provided certificate config.

 @param certificateConfig a base64 encoded string representation of a
 certificate bundle.

 @return A Manual identity using the provided certificate config.
 */
- (instancetype)initManualWithCertificateConfig:(NSString *)certificateConfig;

@end

NS_ASSUME_NONNULL_END
