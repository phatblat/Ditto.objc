//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITSubscription.h>

@class _DITDittoHandleWrapper;

NS_ASSUME_NONNULL_BEGIN

@interface DITSubscription ()

@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly, nullable) NSData *queryArgsData;

- (instancetype)initWithQuery:(NSString *)query
                queryArgsData:(nullable NSData *)queryArgsData
               collectionName:(NSString *)collectionName
           dittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper;
@end

NS_ASSUME_NONNULL_END
