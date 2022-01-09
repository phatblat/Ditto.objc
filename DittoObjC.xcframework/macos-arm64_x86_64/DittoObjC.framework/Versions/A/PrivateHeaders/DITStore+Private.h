//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITStore.h>

@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITStore ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) uint64_t siteID;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
                                    siteID:(uint64_t)siteID;

@end

NS_ASSUME_NONNULL_END
