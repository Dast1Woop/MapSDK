# IndoorMapFramework

[![CI Status](https://img.shields.io/travis/641540230@qq.com/IndoorMapFramework.svg?style=flat)](https://travis-ci.org/641540230@qq.com/IndoorMapFramework)
[![Version](https://img.shields.io/cocoapods/v/IndoorMapFramework.svg?style=flat)](https://cocoapods.org/pods/IndoorMapFramework)
[![License](https://img.shields.io/cocoapods/l/IndoorMapFramework.svg?style=flat)](https://cocoapods.org/pods/IndoorMapFramework)
[![Platform](https://img.shields.io/cocoapods/p/IndoorMapFramework.svg?style=flat)](https://cocoapods.org/pods/IndoorMapFramework)


# 说明

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## 支持
* 本SDK支持竖屏iPhone或iPad；
* 最低支持版本为 iOS**10.0**；

## 更新说明 
### v0.53
* 支持大地图显示；
* 路径规划；
* poi和poi分类搜索；
* ...  

# 使用
## 工程设置：

### Build Settings配置
在TARGETS-Build Settings-Other Linker Flags中添加如下内容：-ObjC;如果已经存在，就无需再添加了。
![e344383adbb87c0cbfe24fe85b75b3b3.png](evernotecid://5826E17D-CECA-4197-86B0-A512EE865D69/appyinxiangcom/12719096/ENResource/p16594)


### info.plist配置
在info.plist中添加如下设置(NSAllowsArbitraryLoads是为了使APP可以访问http协议接口)：
![c3f933e7a3ea819e7c8f44e3ed99c9b6.png](evernotecid://5826E17D-CECA-4197-86B0-A512EE865D69/appyinxiangcom/12719096/ENResource/p16595)
![d48cdae9a030f1770d63a4b387a19fdb.png](evernotecid://5826E17D-CECA-4197-86B0-A512EE865D69/appyinxiangcom/12719096/ENResource/p16596)
如上图，在第一个<dict>下面复制粘贴以下代码（***可能有变化，请注意对比。如已存在，无需再次加入***）：

```swift
<key>MGLMapboxMetricsEnabledSettingShownInApp</key>
<true/>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>APP需要使用定位权限进行GPS定位</string>
<key>NSLocationWhenInUseUsageDescription</key>
<string>APP需要使用定位权限进行GPS定位</string>
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
<true/>
</dict>
```

## 代码设置
### Podfile配置
* Podfile中添加如下库（***可能有变化，请注意对比，如已存在，无需再次加入***）
* 执行 **pod update** 进行更新：
```swift
pod 'IndoorMapFramework'
```

### 代码引用
在需要使用地图的类中，导入下面头文件即可：
`#import <IndoorMapFramework/IndoorMapFramework.h>`

## License

IndoorMapFramework is available under the MIT license. See the LICENSE file for more info.
