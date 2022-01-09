//
//  Copyright © 2021 Ditto. All rights reserved.
//

#import <DittoObjC/DITPendingCollectionsOperation.h>

@class _DITDittoHandleWrapper;
@class DITPendingCursorOperation;

NS_ASSUME_NONNULL_BEGIN

@interface DITPendingCollectionsOperation ()

@property (nonatomic, readonly) DITPendingCursorOperation *pendingCursorOperation;
@property (nonatomic, readonly) uint64_t siteID;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper siteID:(uint64_t)siteID;

@end

NS_ASSUME_NONNULL_END
