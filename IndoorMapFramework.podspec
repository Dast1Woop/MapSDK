#
# Be sure to run `pod lib lint IndoorMapFramework.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'IndoorMapFramework'
    s.version  	       = '0.31.0'
    s.summary          = '地图SDK'
    
    # This description is used to generate tags and improve search results.
    #   * Think: What does it do? Why did you write it? What is the focus?
    #   * Try to keep it short, snappy and to the point.
    #   * Write the description between the DESC delimiters below.
    #   * Finally, don't worry about the indent, CocoaPods strips it!

    #s.description      = <<-DESC
    #地图SDK，具有地图显示，路径规划，POI搜索等功能。
    #DESC
    
    s.homepage         = 'https://github.com/JyyJDast1/MapSDK'
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'myldast1@126.com' => 'myldast1@126.com' }
    s.source           = { :git => 'https://github.com/JyyJDast1/MapSDK.git', :tag => s.version.to_s }
    # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
    
    s.ios.deployment_target = '10.0'
    s.requires_arc = true
    #s.source_files = 'IndoorMapFramework/Classes/**/*'
    
    # s.resource_bundles = {
    #   'IndoorMapFramework' => ['IndoorMapFramework/Assets/*.png']
    # }
    
    # s.public_header_files = 'Pod/Classes/**/*.h'
    s.frameworks = 'UIKit', 'Foundation'
    
    s.dependency 'Mapbox-iOS-SDK','~>4.10.0'
    s.dependency 'MJExtension','~>3.0.17'
    s.dependency 'AFNetworking','~>3.2.1'
    s.dependency 'Masonry','~>1.1.0'
    s.dependency 'Turf', '~> 0.3'
    s.dependency 'YYModel', '~> 1.0.4'
    
    #表示pod库项目依赖自己的framework
    s.vendored_frameworks = 'IndoorMapFramework/*.{framework}'
    #s.resource = 'HTMapBundle.bundle'#会报错
    s.resource_bundles = {
        'HTMapBundle' => ['IndoorMapFramework/HTMapBundle/*.png']
    }
    s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
end
