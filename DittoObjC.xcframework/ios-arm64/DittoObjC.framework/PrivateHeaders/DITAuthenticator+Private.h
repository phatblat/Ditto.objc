//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITAuthenticator.h>
#import <DittoObjC/dittoffi.h>

@class _DITAuthClientWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITAuthenticator()

@property (nonatomic, nullable) _DITAuthClientWrapper *authClientWrapper;

- (instancetype)initWithAuthClient:(nullable _DITAuthClientWrapper *)authClient;

@end

NS_ASSUME_NONNULL_END
