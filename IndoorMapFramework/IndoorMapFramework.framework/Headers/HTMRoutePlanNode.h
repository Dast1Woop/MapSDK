//
//  RoutePlanNode.h
//  IndoorMapFramework
//
//  Created by Xd Huang on 2019/2/22.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HTMGeoCoor.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMRoutePlanNode : HTMGeoCoor<NSCoding, NSCopying>

/** 名称 */
@property(nonatomic, copy) NSString *name;

/** mapID */
@property(nonatomic, copy) NSString *mapId;

///记录导航点在整个导航文本数组中的下标，用于模拟导航功能
@property (nonatomic, assign) NSUInteger pathNumber;

///是否是拐点，用于模拟导航中文本提示回调
@property (nonatomic, assign) BOOL gIsTurningPoint;

/**
 通过经纬度创建路径规划点

 @param lng 经度
 @param lat 纬度
 @return HTMRoutePlanNode 对象
 */
- (instancetype)initWithLng:(double)lng lat:(double)lat;

/**
  通过经纬度创建路径规划点

 @param lng 经度
 @param lat 纬度
 @return TMRoutePlanNode 对象
 */
+ (instancetype)nodeWithLng:(double)lng lat:(double)lat;

/**
 通过经纬度等参数创建路径规划点

 @param lng 经度
 @param lat 纬度
 @param floorID 楼层id
 @param name 节点名
 @param mapId 节点所在地图id
 @return TMRoutePlanNode 对象
 */
+ (instancetype)nodeWithLng:(double)lng
                        lat:(double)lat
                    floorID:(int)floorID
                       name:(NSString *)name
                      mapId:(NSString *)mapId;

- (double)getDistanceWithNode:(HTMRoutePlanNode *)node;


/// 根据AB点和系数（0~1）的值，获取中间点坐标对象
/// @param nodeA 起点
/// @param nodeB 终点
/// @param lanEnTa 系数
+ (instancetype)getObjWithNodeA:(HTMRoutePlanNode *)nodeA nodeB:(HTMRoutePlanNode *)nodeB lanEnTa:(double)lanEnTa;

+ (CLLocationCoordinate2D)getMaxLatAndMaxLngWith:(NSArray <HTMRoutePlanNode *> *)arr;

+ (CLLocationCoordinate2D)getMinLatAndMinLngWith:(NSArray <HTMRoutePlanNode *>  *)arr;

@end

NS_ASSUME_NONNULL_END
