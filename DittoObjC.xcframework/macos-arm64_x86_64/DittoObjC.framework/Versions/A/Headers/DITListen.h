//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITHTTPListenConfig.h>
#import <DittoObjC/DITTCPListenConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Configure this device as a Ditto server. Disabled by default.

 This is advanced usage that is not needed in most situations. Please refer to the documentation
 on Ditto's website for scenarios and example configurations.
 */
@interface DITListen : NSObject<NSCopying, NSMutableCopying> {
    @protected DITTCPListenConfig *_tcp;
    @protected DITHTTPListenConfig *_http;
}

@property (nonatomic, readonly) DITTCPListenConfig *tcp;
@property (nonatomic, readonly) DITHTTPListenConfig *http;

- (instancetype)initWithDITListen:(DITListen *)listen;
- (instancetype)initWithTCP:(DITTCPListenConfig *)tcp
                       HTTP:(DITHTTPListenConfig *)http NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
