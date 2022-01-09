//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocumentIDPath.h>

@class DITDocumentIDPath;

NS_ASSUME_NONNULL_BEGIN

@interface DITDocumentIDPath ()
@property (nonatomic, readonly) id innerValue;
/**
 Contains either a string path component or an integer (as an NSNumber),
 referencing an array index.
 */
@property (nonatomic, readonly) NSArray *pathComponents;

- (instancetype)initWithValue:(id)innerValue path:(NSArray *)pathComponents;

+ (instancetype)documentIDPathFrom:(DITDocumentIDPath *)path appending:(NSObject *)suffix;
@end

NS_ASSUME_NONNULL_END
