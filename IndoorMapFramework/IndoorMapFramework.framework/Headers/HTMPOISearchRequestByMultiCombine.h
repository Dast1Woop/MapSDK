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

/// 包含当前位置经纬度坐标的对象，floorID可传可不传
@property(nonatomic, strong) HTMGeoCoor *crtGeoCoor;

///范围（米）。配合location使用，默认搜索2000m、5000m、所在市
@property (nonatomic, assign) double meter;

///搜索关键字
@property(nonatomic, copy) NSString *keyword;

///室内poi类型
@property(nonatomic, copy) NSString *type;

///菜单类型code。通过字典接口获取
@property(nonatomic, copy) NSString *typeCode;

///室内地图id
@property(nonatomic, copy) NSString *mapId;

///行政区域id
@property(nonatomic, copy) NSString *regionId;

@property (nonatomic, copy) NSArray<NSNumber *> *bbox;

///后台规则：true搜索室内，false搜索室外，null不限
///app规则：1搜索室内，0搜索室外，默认值为-1（不限制，室内+室外）
@property (nonatomic, assign) int indoor;

///每页记录数，默认10。url传参。当 indoor = -1 时不支持分页
@property (nonatomic, assign) int pageSize;

///当前页码，默认1。url传参。当 indoor = -1 时不支持分页
@property (nonatomic, assign) int pageNum;

///优先策略：wheelchair无障碍优先（默认），distance距离优先
@property(nonatomic, copy) NSString *priority;



@end

NS_ASSUME_NONNULL_END
