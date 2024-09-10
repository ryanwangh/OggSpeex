Pod::Spec.new do |s|
  s.name             = "LBSpeex"
  s.version          = "1.0.0"
  s.summary          = "A audio framework for iOS."
  s.description  = <<-DESC
			audio play
                   DESC
  s.homepage         = "homepage"
  s.screenshots     = "screenshots"
  s.license          = 'BSD'
  s.author           = { "Ryan" => ".com" }
  s.source           = { :git => "", :tag => s.version.to_s }
  s.social_media_url = ''

  s.platform      = :ios, '13.0'
  
  s.vendored_frameworks = 'Framework/*.{framework,xcframework}'
  s.source_files = 'Source/**/*.{h,m,mm,cpp,hpp}'
  s.public_header_files = 'Source/LBPlayerManager.h'
  
  s.requires_arc  = true
#  s.libraries    = "c++"
  s.pod_target_xcconfig = {
      "CLANG_CXX_LANGUAGE_STANDARD" => "gnu++20",
#      "CLANG_CXX_LIBRARY" => "libc++",
#      "CLANG_WARN_OBJC_IMPLICIT_RETAIN_SELF" => "NO",
    }

end
