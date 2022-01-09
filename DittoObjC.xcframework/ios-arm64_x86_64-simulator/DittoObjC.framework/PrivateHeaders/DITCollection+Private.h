//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITCollection.h>
#import <DittoObjC/dittoffi.h>

@class DITDocumentID;
@class _DITDittoHandleWrapper;

struct Ditto_WriteTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface DITCollection ()
@property (nonatomic, readonly) _DITDittoHandleWrapper *dittoHandleWrapper;
@property (nonatomic, readonly) uint64_t siteID;

- (instancetype)initWithDittoHandleWrapper:(_DITDittoHandleWrapper *)dittoHandleWrapper
                                      name:(NSString *)name
                                    siteID:(uint64_t)siteID;
- (nullable DITDocumentID *)insert:(NSDictionary<NSString *, id> *)content
                            withID:(nullable DITDocumentID *)id
                     writeStrategy:(DITWriteStrategy)writeStrategy
                          writeTxn:(nullable CWriteTransaction_t *)writeTxn
                             error:(NSError *_Nullable __autoreleasing *)error NS_SWIFT_NAME(insert(_:withID:writeStrategy:writeTxn:));
- (nullable DITDocumentID *)insertCBORData:(NSData *)data
                                    withID:(nullable DITDocumentID *)id
                             writeStrategy:(DITWriteStrategy)writeStrategy
                                  writeTxn:(nullable CWriteTransaction_t *)writeTxn NS_SWIFT_NAME(insertCBORData(_:withID:writeStrategy:writeTxn:));
- (nullable DITDocumentID *)insertCBORData:(NSData *)data
                                    withID:(nullable DITDocumentID *)id
                             writeStrategy:(DITWriteStrategy)writeStrategy
                                     error:(NSError *_Nullable __autoreleasing *)error NS_SWIFT_NAME(insertCBORData(_:withID:writeStrategy:));

- (DITPendingCursorOperation *)find:(NSString *)query withArgsData:(nullable NSData *)queryArgsData;

@end

NS_ASSUME_NONNULL_END
