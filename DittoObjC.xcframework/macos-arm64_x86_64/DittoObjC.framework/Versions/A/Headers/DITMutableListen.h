//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITListen.h>

#import <DittoObjC/DITMutableHTTPListenConfig.h>
#import <DittoObjC/DITMutableTCPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableListen : DITListen

@property (nonatomic, readwrite, strong) DITMutableTCPListenConfig *tcp;
@property (nonatomic, readwrite, strong) DITMutableHTTPListenConfig *http;

@end

NS_ASSUME_NONNULL_END
