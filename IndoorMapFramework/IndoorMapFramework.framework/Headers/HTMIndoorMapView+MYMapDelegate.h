//
//  HTMIndoorMapView+MYMapDelegate.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/4.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <IndoorMapFramework/IndoorMapFramework.h>

NS_ASSUME_NONNULL_BEGIN
@interface HTMIndoorMapView (MYMapDelegate)

@end

@protocol HTMIndoorMapDelegate <NSObject>

@required
/**
 注意：POIQuery初始化必须在此方法内/之后执行
 当mapbox的didFinishLoadingStyle回调成功触发后，回调此方法。
 建议在此方法中蒙版提示”地图加载成功“
 @param indoorMapView 包含MGLMapView *mapView属性的HTMIndoorMapView类型的indoorMapView
 **/
- (void)htmIndoorMapViewDidFinishLoading:(HTMIndoorMapView *)indoorMapView;

@optional


/**
 地图点击事件, point:the CGPoint where the user tapped.

 @param indoorMapView HTMIndoorMapView对象
 @param feature 如果isFeature为YES，feature为包含完整信息的地图feature数据；否则，为nil。
 @param isFeature 点击地图获取的是否是有效的feature数据
 @param coor 地图点击点对应的经纬度坐标
 */
-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView
featureOrMapDidSelected:(MGLPolygonFeature * _Nullable)feature
              isFeature:(BOOL)isFeature
           featureCoor:(CLLocationCoordinate2D)coor;

/**
 *楼层切换事件
 **/
-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView floorDidSelected:(HTMFloorConfig *)floor;


@end

NS_ASSUME_NONNULL_END
