//
//  Copyright © 2021 DittoLive Incorporated. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DittoObjC/DITConnect.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITMutableConnect : DITConnect

@property (nonatomic, readwrite, strong) NSMutableSet<NSString *> *tcpServers;
@property (nonatomic, readwrite, strong) NSMutableSet<NSString *> *websocketURLs;

@end

NS_ASSUME_NONNULL_END
