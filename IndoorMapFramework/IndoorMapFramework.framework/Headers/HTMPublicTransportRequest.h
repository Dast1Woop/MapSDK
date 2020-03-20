//
//  HTMPublicTransportRequest.h
//  IndoorMapFramework
//
//  Created by LongMa on 2020/3/16.
//  Copyright © 2020 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface HTMPublicTransportRequest : NSObject


/*非必须；
 起点所在地点的地图（建筑）id
1.如果是室内则非空值
2.若是和终点所在地图相同，则应该fromMapId=toMapId*/
@property(nonatomic, copy) NSString *fromMapId;

/** 非必须；
1.如果是室内则非空值
2.若是和起点所在地图相同，则应该toMapId=fromMapId */
@property(nonatomic, copy) NSString *toMapId;

/** 必须；
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

// 必须；起点坐标经纬度，fromPoint = lng, lat
@property(nonatomic, copy) NSString *fromPoint;

// 必须；终点坐标经纬度，toPoint = lng, lat
@property(nonatomic, copy) NSString *toPoint;

/** 必须；
 开始楼层id。
1.非空值，必须是整形数字字符串
2.室外地图 fromFloorId=“0” */
@property(nonatomic, copy) NSString *fromFloorId;

/** 必须；
 结束楼层id
1.非空值，必须是整形数字字符串
2.室外地图 toFloorId=“0” */
@property(nonatomic, copy) NSString *toFloorId;

/** 非必须；
 公交换乘策略
1.可选值（默认值 0）：
0：最快捷模式 （推荐模式）
1：最经济模式
2：最少换乘模式
3：最少步行模式
5：不乘地铁模式 */
@property (nonatomic, assign) int strategy;

/** 非必须；
 是否计算夜班车
1.可选值（默认值 0）：
0：不计算夜班车
1：计算夜班车 */
@property (nonatomic, assign) int nightFlag;

/** 非必须；
 出发时间
1.时间格式为 yyyy-MM-dd HH:mm:ss （24小时制）
2.在无需设置预计出发时间时，请不要在请求之中携带此参数。 */
@property(nonatomic, copy) NSString *dateTime;

/** 非必须；
 是否终点只规划到门口
1.当只为true时，路径规划终点将只规划到门口 （目前只支持室内的门）
2.默认值为false */
@property (nonatomic, assign) BOOL toDoor;

@end

NS_ASSUME_NONNULL_END
