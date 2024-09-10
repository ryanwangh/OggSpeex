//
//  LBPlayerManager.h
//  OggSpeex
//
//  Created by Ryan on 2024/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LBPlayerManager : NSObject

- (void)play:(NSString *)path;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
