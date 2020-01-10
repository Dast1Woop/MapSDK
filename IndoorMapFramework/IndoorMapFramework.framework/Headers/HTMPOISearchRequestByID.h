//
//  HTMPOISearchRequestByID
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 根据 行政区域id或地图id 获取POI信息,未注明“非必须”的属性必须有值
 */
@interface HTMPOISearchRequestByID : NSObject

/// 每页记录数
@property (nonatomic, assign) int pageSize;

/// 当前页码
@property (nonatomic, assign) int pageNum;

///行政区域id，与mapId只能二选一进行赋值
@property(nonatomic, copy) NSString *regionId;

/// 地图ID，一般指的是建筑id，与regionId只能二选一进行赋值
@property(nonatomic, copy) NSString *mapId;

///分类id, 非必须
@property(nonatomic, copy) NSString *type;

/// 模糊搜索关键字， 非必须
@property(nonatomic, copy) NSString *keyword;

///0:获取不支持路径规划，1:获取支持路径规划，默认为 -1 不限制; 非必须
@property (nonatomic, assign) int accessible;

//指定地图（建筑）楼层id;非必须。
@property(nonatomic, copy) NSString *floorId;

//当前位置经纬度坐标,用英文逗号分隔。eg："119.5451145111, 30.77849033578";非必须
@property(nonatomic, copy) NSString *location;

//用户当前所在楼层id;非必须。后台用此参数对所有楼层poi进行距离计算和排序。
@property(nonatomic, copy) NSString *onFloorId;

//优先策略：wheelchair无障碍优先（默认），distance距离优先;非必须
@property(nonatomic, copy) NSString *priority;

@end

NS_ASSUME_NONNULL_END
