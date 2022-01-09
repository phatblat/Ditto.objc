//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocumentPath.h>

@class DITDocumentID;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocumentPath ()
@property (nonatomic, readonly) NSDictionary<NSString *, id> *innerValue;
@property (nonatomic, readonly) DITDocumentID *docID;
/**
 Contains either a string path component or an integer (as an NSNumber),
 referencing an array index.
 */
@property (nonatomic, readonly) NSArray *pathComponents;

- (instancetype)initWithValue:(NSDictionary<NSString *, id> *)innerValue
                   documentID:(DITDocumentID *)docID
                         path:(NSArray *)pathComponents;

+ (instancetype)documentPathFrom:(DITDocumentPath *)path appending:(NSObject *)suffix;
@end

NS_ASSUME_NONNULL_END
