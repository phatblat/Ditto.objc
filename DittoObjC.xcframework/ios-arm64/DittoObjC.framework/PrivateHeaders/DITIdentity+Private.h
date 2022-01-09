//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITIdentity.h>
#import <DittoObjC/dittoffi.h>

@class DITAuthenticator;
@class _DITLoginProvider;
@class _DITAuthClientWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITIdentity()

@property (nonatomic) _DITAuthClientWrapper *authClientWrapper;

@property (nonatomic, readwrite, nullable) DITAuthenticator *authenticator;
@property (nonatomic, readwrite, nullable) _DITLoginProvider *loginProvider;

- (instancetype)initDevelopmentWithAppID:(nullable NSString *)appID
                            siteIDNumber:(nullable NSNumber *)siteID
                    persistenceDirectory:(nullable NSURL *)directory;
- (instancetype)initOfflinePlaygroundWithAppID:(nullable NSString *)appID
                                  siteIDNumber:(nullable NSNumber *)siteID
                          persistenceDirectory:(nullable NSURL *)directory;
- (instancetype)initSharedKeyWithAppID:(NSString *)appID
                             sharedKey:(NSString *)sharedKey
                          siteIDNumber:(nullable NSNumber *)siteID
                  persistenceDirectory:(nullable NSURL *)directory;;

@end

NS_ASSUME_NONNULL_END
