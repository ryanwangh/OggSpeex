//
// Copyright © 2013-2024 Stephen F. Booth <me@sbooth.org>
// Part of https://github.com/sbooth/AVFAudioExtensions
// MIT license
//

#import <AVFAudio/AVFAudio.h>

NS_ASSUME_NONNULL_BEGIN

/// Functions for building channel layouts from channel labels
@interface AVAudioChannelLayout (SFBChannelLabels)
/// Returns an initialized `AVAudioChannelLayout` object with the specified channel labels or `nil` on failure
/// - parameter count: The number of channel labels
+ (nullable instancetype)layoutWithChannelLabels:(AVAudioChannelCount)count, ...;
/// Returns an initialized `AVAudioChannelLayout` object with the specified channel labels or `nil` on failure
/// - parameter channelLabels: An array of channel labels
/// - parameter count: The number of channel labels
+ (nullable instancetype)layoutWithChannelLabels:(const AudioChannelLabel *)channelLabels count:(AVAudioChannelCount)count;
/// Returns an initialized `AVAudioChannelLayout` object according to the specified channel label string or `nil` on failure
/// - parameter channelLabelString: A string containing the channel labels
+ (nullable instancetype)layoutWithChannelLabelString:(NSString *)channelLabelString;
/// Returns an initialized `AVAudioChannelLayout` object with the specified channel labels or `nil` on failure
/// - parameter count: The number of channel labels
- (nullable instancetype)initWithChannelLabels:(AVAudioChannelCount)count, ...;
/// Returns an initialized `AVAudioChannelLayout` object with the specified channel labels or `nil` on failure
/// - parameter count: The number of channel labels
/// - parameter ap: A variadic argument list containing `count` `AudioChannelLabel` parameters
- (nullable instancetype)initWithChannelLabels:(AVAudioChannelCount)count ap:(va_list)ap;
/// Returns an initialized `AVAudioChannelLayout` object with the specified channel labels or `nil` on failure
/// - parameter channelLabels: An array of channel labels
/// - parameter count: The number of channel labels
- (nullable instancetype)initWithChannelLabels:(const AudioChannelLabel *)channelLabels count:(AVAudioChannelCount)count;
/// Returns an initialized `AVAudioChannelLayout` object according to the specified channel label string or `nil` on failure
/// - note: The string comparisons are case-insensitive
///
/// The following channel label strings are recognized:
/// L `kAudioChannelLabel_Left`
/// R `kAudioChannelLabel_Right`
/// C `kAudioChannelLabel_Center`
/// LFE `kAudioChannelLabel_LFEScreen`
/// Ls `kAudioChannelLabel_LeftSurround`
/// Rs `kAudioChannelLabel_RightSurround`
/// Lc `kAudioChannelLabel_LeftCenter`
/// Rc `kAudioChannelLabel_RightCenter`
/// Cs `kAudioChannelLabel_CenterSurround`
/// Lsd `kAudioChannelLabel_LeftSurroundDirect`
/// Rsd `kAudioChannelLabel_RightSurroundDirect`
/// Tcs `kAudioChannelLabel_TopCenterSurround`
/// Vhl `kAudioChannelLabel_VerticalHeightLeft`
/// Vhc `kAudioChannelLabel_VerticalHeightCenter`
/// Vhl `kAudioChannelLabel_VerticalHeightRight`
/// RLs `kAudioChannelLabel_RearSurroundLeft`
/// RRs `kAudioChannelLabel_RearSurroundRight`
/// Lw `kAudioChannelLabel_LeftWide`
/// Rw `kAudioChannelLabel_RightWide`
/// All other strings are mapped to `kAudioChannelLabel_Unknown`
/// - parameter channelLabelString: A string containing the channel labels
- (nullable instancetype)initWithChannelLabelString:(NSString *)channelLabelString NS_SWIFT_NAME(init(channelLabelString:));
@end

NS_ASSUME_NONNULL_END
