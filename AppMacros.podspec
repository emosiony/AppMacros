#
#  Be sure to run `pod spec lint iOS_AppMacros.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "AppMacros"
  s.version      = "0.1.0"
  s.summary      = "some macros methed for iOS develop"
  s.description  = <<-DESC
                   this project provide some macros methed for iOS developer
                    DESC
  s.homepage     = "https://git.oschina.net/eMoision/AppMacros"
  s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "一抹哀伤" => "1403660461@qq.com" }
  s.platform     = :ios
  s.ios.deployment_target = "7.0"
  s.source       = { :git => "https://git.oschina.net/eMoision/AppMacros.git", :tag => s.version.to_s }
  s.source_files  = "AppMacros/Classes/**/*{h,m}"
  #s.exclude_files = "Classes/Exclude"
  #s.public_header_files = "AppMacros/Classes/**/*.h"
  s.requires_arc = true

end
