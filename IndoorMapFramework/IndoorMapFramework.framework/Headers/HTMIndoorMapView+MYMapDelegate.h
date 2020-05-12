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
已过期，DEPRECATED_MSG_ATTRIBUTE("推荐使用 htmMapView:visibleFeaturesInTouchedRect:touchCoor:featureCoor:")
 @param indoorMapView HTMIndoorMapView对象
 @param feature 如果isFeature为YES，feature为包含完整信息的地图feature数据；否则，为nil。
 @param isFeature 点击地图获取的是否是有效的feature数据
 @param coor 地图点击点对应的经纬度坐标
 
 */
-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView
featureOrMapDidSelected:(MGLPolygonFeature * _Nullable)feature
              isFeature:(BOOL)isFeature
            featureCoor:(CLLocationCoordinate2D)coor;

/// 地图点击事件，适用于大地图室内外poi、线路、面模型点击事件
/// @param mapView HTMMapView对象
/// @param featuresArr  包含poi、线路、面模型的数组。已分组：(低地址)poi(MGLPointFeature)模型数组，线模型(MGLPolylineFeature)数组，面(MGLPolygonFeature)模型数组。eg：3种模型都有时，第0位是MGLPointFeature模型
/// @param touchCoor 触摸点经纬度
/// @param featureCoor featuresArr的第0个模型绑定的经纬度，如果为(0,0),内部会把touchCoor赋值给它.
-(void)htmMapView:(HTMIndoorMapView *)mapView
visibleFeaturesInTouchedRect:(NSArray *)featuresArr
        touchCoor:(CLLocationCoordinate2D)touchCoor
      featureCoor:(CLLocationCoordinate2D)featureCoor;

/**
  建筑/楼层 切换事件

 @param indoorMapView HTMIndoorMapView对象
 @param floorM 楼层模型
 @param buildingM 建筑模型
 */
-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView
         didSelectFloor:(HTMFloorModel *)floorM
               building:(HTMBuildingModel *)buildingM;

/// 对建筑列表的cell 普通样式 设置代理。不实现此代理的效果为白底黑字
/// @param indoorMapView 地图对象
/// @param cell cell对象
- (void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView buildingListCell4ConfigNormalStyle:(UITableViewCell *)cell;

/// 对建筑列表的cell 选中样式(只有正在显示的建筑名有选中效果) 设置代理，不实现此代理的效果为蓝底白字
/// @param indoorMapView 地图对象
/// @param cell cell对象
- (void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView     buildingListCell4ConfigSelectedStyle:(UITableViewCell *)cell;

/// 设置楼层选择器中处于选中状态的的label的样式
/// @param indoorMapView 地图对象
/// @param label 处于选中状态的的label
- (void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView selectedLabel4ConfigStyleInPikerView:(UILabel *)label;

@end

NS_ASSUME_NONNULL_END
