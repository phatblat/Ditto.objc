//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DittoObjC/DITAuthenticationDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides access to authentication information and methods for logging on to
 Ditto Cloud. Relevant when using an `OnlineWithAuthentication` or an `Online`
 identity.
 */
@interface DITAuthenticator : NSObject

/**
 Log in to Ditto with a third-party token.

 @param token the authentication token required to log in.
 @param provider the name of the authentication provider.
 @param completion a block that will get called when the login attempt has
 completed.
 */
- (void)loginWithToken:(NSString *)token
              provider:(nullable NSString *)provider
            completion:(void (^)(NSError * __nullable))completion;

/**
 Log in to Ditto with a username and password.

 @param username the username component of the credentials used for log in.
 @param password the password component of the credentials used for log in.
 @param provider the name of the authentication provider.
 @param completion a block that will get called when the login attempt has
 completed.
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
                 provider:(nullable NSString *)provider
               completion:(void (^)(NSError * __nullable))completion;

/**
 Query whether Ditto has a valid authentication token.

 This will only be `YES` when using an `OnlineWithAuthentication` or an `Online`
 identity, after a successful login. If the authentication token is allowed to
 expire then it will return `NO` instead.
 */
- (BOOL)isAuthenticated;

/**
 Return the currently logged-in user ID.

 This will return `nil` if there is no valid authentication or
 `OnlineWithAuthentication`/`Online` mode is not being used.
 */
- (NSString *_Nullable)userID;

@end

NS_ASSUME_NONNULL_END
