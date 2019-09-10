//
//  HTMPOISearchRequestByMultiCombine.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/9/10.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
@class HTMGeoCoor;
NS_ASSUME_NONNULL_BEGIN


/**
 根据关键字等组合信息搜索POI信息，根据需求自由组合参数（每一项都是非必传），一般不必设置所有参数。
 */
@interface HTMPOISearchRequestByMultiCombine : NSObject

/// 包含当前位置经纬度坐标的对象，floorID 非必须
@property(nonatomic, strong) HTMGeoCoor *crtGeoCoor;

///范围（米）。配合location使用，默认搜索2000m、5000m、所在市
@property (nonatomic, assign) double meter;

///搜索关键字
@property(nonatomic, copy) NSString *keyword;

///菜单类型code。通过字典接口获取
@property(nonatomic, copy) NSString *typeCode;

///室内地图id
@property(nonatomic, copy) NSString *mapId;

///行政区域id
@property(nonatomic, copy) NSString *regionId;

@property (nonatomic, copy) NSArray<NSNumber *> *bbox;

///true搜索室内，false搜索室外，null不限
@property (nonatomic, assign) BOOL indoor;

///每页记录数，默认10。url传参。当 indoor = null 时不支持分页
@property (nonatomic, assign) int pageSize;

///当前页码，默认1。url传参。当 indoor = null 时不支持分页
@property (nonatomic, assign) int pageNum;

///0获取不支持路径规划（不可点击），默认1获取支持路径规划（可点击）
@property (nonatomic, assign) int group;

///优先策略：wheelchair无障碍优先（默认），distance距离优先
@property(nonatomic, copy) NSString *priority;



@end

NS_ASSUME_NONNULL_END
