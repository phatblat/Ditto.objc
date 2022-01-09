//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITUpdateResult.h>

@class DITDocumentID;

NS_ASSUME_NONNULL_BEGIN

@interface DITUpdateResultSet ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path value:(id)value;
@end

@interface DITUpdateResultRemoved ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path;
@end

@interface DITUpdateResultReplacedWithCounter ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path;
@end

@interface DITUpdateResultIncremented ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path amount:(double)amount;
@end

@interface DITUpdateResultPushed ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path value:(id)value;
@end

@interface DITUpdateResultPopped ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path value:(id)value;
@end

@interface DITUpdateResultInserted ()
- (instancetype)initWithDocID:(DITDocumentID *)docID path:(NSString *)path value:(id)value;
@end

NS_ASSUME_NONNULL_END
