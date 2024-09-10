//
//  LBPlayerManager.m
//  OggSpeex
//
//  Created by Ryan on 2024/9/9.
//

#import "LBPlayerManager.h"
#import "SFBAudioPlayer.h"
#import "SFBOggSpeexDecoder.h"

@interface LBPlayerManager ()

@property (nonatomic, strong) SFBAudioPlayer* player;

@end

@implementation LBPlayerManager

- (void)play:(NSString *)path {
    SFBOggSpeexDecoder *decoder = [[SFBOggSpeexDecoder alloc] initWithURL:[NSURL fileURLWithPath:path]];
    
    NSError *error;
    [self.player playDecoder:decoder error:&error];
    if (error) {
        NSLog(@"%@", error);
    }
}

- (void)stop {
    [self.player stop];
}

- (SFBAudioPlayer *)player {
    if (!_player) {
        _player = [[SFBAudioPlayer alloc] init];
    }
    return _player;
}

@end
