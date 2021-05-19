//
//  HTMRouteSearchRequest.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMGeoCoor;
#import "HTMEnumDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface HTMRouteSearchRequest : NSObject

/**
 起点所在地点的地图（建筑）id
 1.如果是室内则非空值，室外无需赋值
 2.若是和终点所在地图相同，则应该fromMapId=toMapId
 */
@property(nonatomic, copy) NSString *fromMapId;

/** 终点所在地点的地图（建筑）id
 1.如果是室内则非空值，室外无需赋值
 2.若是和起点所在地图相同，则应该toMapId=fromMapId
 */
@property(nonatomic, copy) NSString *toMapId;

/// 起点模型：必须对经纬度和floorID属性赋值
@property(nonatomic, strong) HTMGeoCoor *fromGeoCoor;

/// 终点模型：必须对经纬度和floorID属性赋值
@property(nonatomic, strong) HTMGeoCoor *toGeoCoor;

/// 规划策略, 默认是BY_TIME（时间优先）
@property (nonatomic, assign) RoutePlanType planType;

/**
 希望返回首要语言类型
 1.非空值，2.值为以下之一（区分大小写）：
 zh_cn (简体中文)
 zh_tw（[台湾]繁体中文）
 zh_hk （[香港] 繁体中文）
 zh_mo （[澳门] 繁体中文）
 en（英文）
 pt（葡文）
 */
@property(nonatomic, copy) NSString *lang;


/** 非必传，路径类型，起点和终点是否加入路径
默认值是1，值只能是以下之一：
0 起点加入路径
1 终点加入路径（默认值）
2 起点和终点加入路径
3 起点和终点均不加入路径（只用路网绘制的路径） */
@property (nonatomic, assign) int pathType;

/// 非必传    是否终点只规划到门口    当只为true时，路径规划终点将只规划到门口 （目前只支持室内的门）
@property (nonatomic, assign) BOOL toDoor;

//MARK: 终点只规划到（室外）建筑出入口 相关的3个字段toEntrance、osmIdType、toOsmId
/**
 非必传，如果传，只能传 @0 或 @1 ；
 toEntrance、 osmIdType、toOsmId 同时传递才会尝试“终点只规划到（室外）建筑出入口”；
 
 接口文档说明：
 是否终点只规划到（室外）建筑出入口；
 当只为 true 时，路径规划终点将只规划到建筑门口 （目前只支持室外的建筑）；
 */
@property (nonatomic,strong,nullable) NSNumber *toEntrance;

/**
 非必传，如果传，只能传 @0 或 @1 ；
 toEntrance、 osmIdType、toOsmId 同时传递才会尝试“终点只规划到（室外）建筑出入口”；
 
 接口文档说明：
 1.瓦片获取到的id为非原始id，osmIdType值为0
 2.从其它接口（如搜索）获取的osm id，osmIdType值为1
 */
@property (nonatomic,strong,nullable) NSNumber *osmIdType;

/**
 非必传，toEntrance、 osmIdType、toOsmId 同时传递才会尝试“终点只规划到（室外）建筑出入口”；
 值为@"0"时（搜索结果中室内 poi 的 osmId 可能为0），无需赋值，即使赋值，也不会在请求中传递（如果传递，后台规划路线必定失败）。
 
 接口文档说明：
 终点室外poi的osm id
 */
@property (nonatomic,copy,nullable) NSString *toOsmId;

/// app版本号, 非必传
@property (nonatomic,copy) NSString *appVersion;

/// @"ios"，只读
@property (nonatomic,copy,readonly) NSString *device;

/// sdk版本号，只读
@property (nonatomic,copy,readonly) NSString *sdkVersion;



@end

NS_ASSUME_NONNULL_END
