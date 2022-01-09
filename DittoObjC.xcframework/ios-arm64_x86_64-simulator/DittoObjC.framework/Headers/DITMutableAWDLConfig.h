//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITAWDLConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableAWDLConfig : DITAWDLConfig

@property (nonatomic, readwrite, getter = isEnabled) BOOL enabled;

@end

NS_ASSUME_NONNULL_END
