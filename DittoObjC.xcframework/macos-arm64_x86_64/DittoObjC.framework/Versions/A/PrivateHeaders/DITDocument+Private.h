//
//  Copyright © 2020 DittoLive Incorporated. All rights reserved.
//

#import <DittoObjC/DITDocument.h>

#import <DittoObjC/dittoffi.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITDocument ()
@property (nonatomic, readonly, unsafe_unretained) CDocument_t *documentHandle;

- (instancetype)initWithDocumentHandle:(CDocument_t *)documentHandle;
@end

NS_ASSUME_NONNULL_END
