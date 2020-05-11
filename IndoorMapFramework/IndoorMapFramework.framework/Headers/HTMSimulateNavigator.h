//
//  HTMSimulateNavigator.h
//  IndoorMapFramework
//
//  Created by LongMa on 2020/5/6.
//  Copyright © 2020 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMRoutePath;
@class HTMIndoorMapView;
@class HTMRoutePlanNode;
@class HTMRoutePlanInstruction;

@protocol HTMSimulateNavigatorDelegate;

NS_ASSUME_NONNULL_BEGIN

/// 注意：使用时必须强引用此类的对象！
@interface HTMSimulateNavigator : NSObject

/// 地图对象
@property(nonatomic, strong) HTMIndoorMapView *gIndoorMapView;

/// 路径规划成功后，返回的对象
@property(nonatomic, strong) HTMRoutePath *gRoutePath;

/// 模拟移动速度，单位m/s。注意：速度即使很快，每一段路至少也会模拟行走一次。
@property (nonatomic, assign) float speed;

///模拟定位点图片名
@property(nonatomic, copy) NSString *gStr4SimLocateImgName;

@property (nonatomic, weak) id<HTMSimulateNavigatorDelegate> delegateCustom;

- (instancetype)initWithIndoorMapView:(HTMIndoorMapView *)indoorMapV
                            routePath:(HTMRoutePath *)routePath
                                speed:(float)speed
                     simLocateImgName:(NSString *)simLocateImgName;

+ (instancetype)modelWithIndoorMapView:(HTMIndoorMapView *)indoorMapV
                             routePath:(HTMRoutePath *)routePath
                                 speed:(float)speed
                      simLocateImgName:(NSString *)simLocateImgName;


/// 开始模拟导航效果。上面属性必须都有值。
- (nullable NSError *)startSimulateNavigation;

/// 暂停模拟导航效果（模拟导航点停止移动）
- (void)pauseSimulateNavigation;

/// 继续模拟导航效果（模拟导航点继续从刚刚暂停的地方移动，如果没有暂停过，从起点开始移动）
- (nullable NSError *)resumeSimulateNavigation;

/// 停止模拟导航效果。模拟定位marker和走过的灰色导航线会被清空。
- (void)stopSimulateNavigation;

@end


@protocol HTMSimulateNavigatorDelegate <NSObject>


/// 模拟导航过程回调
/// @param simNavigator HTMSimulateNavigator对象
/// @param turningPoint 拐点对象
/// @param nextInstruction 下一条路的导航信息对象
- (void)dmSimulateNavigation:(HTMSimulateNavigator *)simNavigator
       didMoveToTurningPoint:(HTMRoutePlanNode *)turningPoint
             nextInstruction:(nullable HTMRoutePlanInstruction *)nextInstruction;


/// 模拟导航结束回调
/// @param simNavigator HTMSimulateNavigator对象
- (void)dmSimulateNavigationDidFinished:(HTMSimulateNavigator *)simNavigator;

@end

NS_ASSUME_NONNULL_END
