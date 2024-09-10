//
// Copyright © 2020-2024 Stephen F. Booth <me@sbooth.org>
// Part of https://github.com/sbooth/AVFAudioExtensions
// MIT license
//

#import <AVFAudio/AVFAudio.h>

NS_ASSUME_NONNULL_BEGIN

/// Useful functions for PCM buffer manipulation
@interface AVAudioPCMBuffer (SFBBufferUtilities)
/// Prepends the contents of `buffer` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - returns: The number of frames prepended
- (AVAudioFrameCount)prependContentsOfBuffer:(AVAudioPCMBuffer *)buffer NS_SWIFT_NAME(prepend(_:));
/// Prepends frames from `buffer` starting at `offset` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter offset: The desired starting offset in `buffer`
/// - returns: The number of frames prepended
- (AVAudioFrameCount)prependFromBuffer:(AVAudioPCMBuffer *)buffer readingFromOffset:(AVAudioFrameCount)offset NS_SWIFT_NAME(prepend(_:from:));
/// Prepends at most `frameLength` frames from `buffer` starting at `offset` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter offset: The desired starting offset in `buffer`
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames prepended
- (AVAudioFrameCount)prependFromBuffer:(AVAudioPCMBuffer *)buffer readingFromOffset:(AVAudioFrameCount)offset frameLength:(AVAudioFrameCount)frameLength NS_SWIFT_NAME(prepend(_:from:length:));

/// Appends the contents of `buffer` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - returns: The number of frames appended
- (AVAudioFrameCount)appendContentsOfBuffer:(AVAudioPCMBuffer *)buffer NS_SWIFT_NAME(append(_:));
/// Appends frames from `buffer` starting at `offset` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter offset: The desired starting offset in `buffer`
/// - returns: The number of frames appended
- (AVAudioFrameCount)appendFromBuffer:(AVAudioPCMBuffer *)buffer readingFromOffset:(AVAudioFrameCount)offset NS_SWIFT_NAME(append(_:from:));
/// Appends at most `frameLength` frames from `buffer` starting at `offset` to `self`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter offset: The desired starting offset in `buffer`
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames appended
- (AVAudioFrameCount)appendFromBuffer:(AVAudioPCMBuffer *)buffer readingFromOffset:(AVAudioFrameCount)offset frameLength:(AVAudioFrameCount)frameLength NS_SWIFT_NAME(append(_:from:length:));

/// Inserts the contents of `buffer` in `self` starting at `offset`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter offset: The desired starting offset in `self`
/// - returns: The number of frames inserted
- (AVAudioFrameCount)insertContentsOfBuffer:(AVAudioPCMBuffer *)buffer atOffset:(AVAudioFrameCount)offset NS_SWIFT_NAME(insert(_:at:));

/// Inserts at most `readLength` frames from `buffer` starting at `readOffset` to `self` starting at `writeOffset`
/// - important: The format of `buffer` must match the format of `self`
/// - parameter buffer: A buffer of audio data
/// - parameter readOffset: The desired starting offset in `buffer`
/// - parameter frameLength: The desired number of frames
/// - parameter writeOffset: The desired starting offset in `self`
/// - returns: The number of frames inserted
- (AVAudioFrameCount)insertFromBuffer:(AVAudioPCMBuffer *)buffer readingFromOffset:(AVAudioFrameCount)readOffset frameLength:(AVAudioFrameCount)frameLength atOffset:(AVAudioFrameCount)writeOffset NS_SWIFT_NAME(insert(_:from:length:at:));

/// Deletes at most the first `frameLength` frames from `self`
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames deleted
- (AVAudioFrameCount)trimFirst:(AVAudioFrameCount)frameLength;
/// Deletes at most the last `frameLength` frames from `self`
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames deleted
- (AVAudioFrameCount)trimLast:(AVAudioFrameCount)frameLength;
/// Deletes at most `frameLength` frames from `self` starting at `offset`
/// - parameter offset: The desired starting offset
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames deleted
- (AVAudioFrameCount)trimAtOffset:(AVAudioFrameCount)offset frameLength:(AVAudioFrameCount)frameLength NS_SWIFT_NAME(trim(at:length:));

/// Fills the remainder of `self` with silence
/// - returns: The number of frames of silence appended
- (AVAudioFrameCount)fillRemainderWithSilence;
/// Appends at most `frameLength` frames of silence to `self`
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames of silence appended
- (AVAudioFrameCount)appendSilenceOfLength:(AVAudioFrameCount)frameLength;
/// Inserts at most `frameLength` frames of silence to `self` starting at `offset`
/// - parameter offset: The desired starting offset
/// - parameter frameLength: The desired number of frames
/// - returns: The number of frames of silence inserted
- (AVAudioFrameCount)insertSilenceAtOffset:(AVAudioFrameCount)offset frameLength:(AVAudioFrameCount)frameLength NS_SWIFT_NAME(silence(at:length:));

/// Returns `YES` if `self.frameLength == 0`
- (BOOL)isEmpty;
/// Returns `YES` if `self.frameLength == self.frameCapacity`
- (BOOL)isFull;

/// Returns `YES` if `self` contains only digital silence
- (BOOL)isDigitalSilence;
@end

NS_ASSUME_NONNULL_END
