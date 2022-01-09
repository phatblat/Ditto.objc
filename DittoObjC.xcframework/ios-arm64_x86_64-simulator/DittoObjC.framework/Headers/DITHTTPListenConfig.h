//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITHTTPListenConfig : NSObject<NSCopying, NSMutableCopying> {
    @protected BOOL _enabled;
    @protected NSString *_interfaceIp;
    @protected uint16_t _port;
    @protected NSString *_staticContentPath;
    @protected BOOL _websocketSync;
    @protected NSString *_tlsKeyPath;
    @protected NSString *_tlsCertificatePath;
    @protected BOOL _isIdentityProvider;
    @protected NSString *_identityProviderSigningKey;
    @protected NSArray<NSString *> *_identityProviderVerifyingKeys;
    @protected NSString *_caKey;
}

@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;
/**
 IP interface to bind to. [::] by default.
 */
@property (nonatomic, readonly) NSString *interfaceIp;
/**
 Listening port. 80 by default.
 */
@property (nonatomic, readonly) uint16_t port;
/**
 An absolute path to a directory of static HTTP content that should be served by this device.

 If nil (default), this feature is disabled.
 */
@property (nonatomic, readonly, nullable) NSString *staticContentPath;
/**
 If YES (default), peers can connect over websocket to sync with this peer.

 This feature has security implications and should only be used together with documentation on Ditto's website.
 */
@property (nonatomic, readonly) BOOL websocketSync;
/**
 An absolute path to the PEM-formatted private key for HTTPS. Must be set together with tlsCertificatePath.

 If nil, the server runs as unencrypted HTTP.
 */
@property (nonatomic, readonly, nullable) NSString *tlsKeyPath;
/**
 An absolute path to the PEM-formatted certificate for HTTPS. Must be set together with tlsKeyPath.

 If nil, the server runs as unencrypted HTTP.
 */
@property (nonatomic, readonly, nullable) NSString *tlsCertificatePath;
/**
 Enable acting as a provider of Ditto identities.
 */
@property (nonatomic, readonly) BOOL isIdentityProvider;
/**
 PEM-encoded private key for signing tokens and certificates when acting as an identity provider.
 */
@property (nonatomic, readonly, nullable) NSString *identityProviderSigningKey;
/**
 PEM-encoded public keys for verifying tokens and certificates when acting as an identity provider.
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *identityProviderVerifyingKeys;
/**
 PEM-encoded private key that should be used to issue certificates for clients in peer-to-peer mode.
 */
@property (nonatomic, readonly, nullable) NSString *caKey;


- (instancetype)initWithDITHTTPListenConfig:(DITHTTPListenConfig *)config;
- (instancetype)initWithEnabled:(BOOL)enabled
                    interfaceIp:(NSString *)interfaceIp
                           port:(uint16_t)port
              staticContentPath:(NSString * __nullable)staticContentPath
                  websocketSync:(BOOL)websocketSync
                     tlsKeyPath:(NSString * __nullable)tlsKeyPath
             tlsCertificatePath:(NSString * __nullable)tlsCertificatePath
             isIdentityProvider:(BOOL)isIdentityProvider
     identityProviderSigningKey:(NSString * __nullable)identityProviderSigningKey
  identityProviderVerifyingKeys:(NSArray<NSString *> * __nullable)identityProviderVerifyingKeys
                          caKey:(NSString * __nullable)caKey NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToDITHTTPListenConfig:(DITHTTPListenConfig *)config;

@end

NS_ASSUME_NONNULL_END
