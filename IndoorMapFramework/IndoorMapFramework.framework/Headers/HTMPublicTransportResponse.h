#import <Foundation/Foundation.h>

@class HTMPublicTransportResponse;
@class HTMPTData;
@class HTMPTPath;
@class HTMPTSegment;
@class HTMPTBus;
@class HTMPTBusLine;
@class HTMPTPlace;
@class HTMPTBusLineStop;
@class HTMPTRouteInfo;
@class HTMPTEntrance;
@class HTMPTRailway;
@class HTMPTRailwayStop;
@class HTMPTSpace;
@class HTMPTWalking;
@class HTMPTStep;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Object interfaces




@interface HTMPublicTransportResponse : NSObject<NSCopying, NSCoding>
@property (nonatomic, strong) HTMPTData *data;

//000 表示 成功
@property (nonatomic, copy)   NSString *code;
@property (nonatomic, copy)   NSString *message;
@end




@interface HTMPTData : NSObject<NSCopying, NSCoding>

//可行的路径方案数
@property (nonatomic, assign) NSUInteger total;

//可行的路径方案集合
@property (nonatomic, copy)   NSArray<HTMPTPath *> *paths;
@end




@interface HTMPTPath : NSObject<NSCopying, NSCoding>

//该方案路径总长，单位为米。保留1位小数
@property (nonatomic, assign) double distance;

//该方案步行路径总长，单位为米。保留1位小数
@property (nonatomic, assign) double walkingDistance;

//该方案耗费总时长，单位为毫秒
@property (nonatomic, assign) NSUInteger duration;

//总票价（元）
@property (nonatomic, assign) NSUInteger cost;

//是否夜班车 0：非夜班车；1：夜班车
@property (nonatomic, assign) int nightFlag;

//换乘路段列表
@property (nonatomic, copy)   NSArray<HTMPTSegment *> *segments;
@end




@interface HTMPTSegment : NSObject<NSCopying, NSCoding>

//此路段步行导航信息
@property (nonatomic, nullable, strong) HTMPTWalking *walking;

//此路段公交导航信息
@property (nonatomic, nullable, strong) HTMPTBus *bus;

//地铁入口,只在地铁路段有值
@property (nonatomic, nullable, strong) HTMPTEntrance *entrance;

//地铁出口,只在地铁路段有值
@property (nonatomic, nullable, strong) HTMPTEntrance *exit;

//乘坐火车的信息
@property (nonatomic, nullable, strong) HTMPTRailway *railway;
@end




@interface HTMPTWalking : NSObject<NSCopying, NSCoding>

//起点坐标，lng,lat
@property (nonatomic, copy)   NSString *origin;

//终点坐标，lng,lat
@property (nonatomic, copy)   NSString *destination;

//每段线路步行距离，单位为米。保留1位小数
@property (nonatomic, assign) double distance;

//步行预计时间，单位为毫秒
@property (nonatomic, assign) NSUInteger duration;

//步行路段列表
@property (nonatomic, copy)   NSArray<HTMPTStep *> *steps;
@end




@interface HTMPTStep : NSObject<NSCopying, NSCoding>

//指示文字
@property (nonatomic, copy)           NSString *text;

//路段名称
@property (nonatomic, nullable, copy)           NSString *name;

//该段路距离，单位为米。保留1位小数
@property (nonatomic, assign)         double distance;

//该段路预计时间，单位为毫秒
@property (nonatomic, assign)         NSUInteger duration;

//该段路坐标数组，[[lng,lat],....]
@property (nonatomic, copy)           NSArray<NSArray<NSNumber *> *> *coordinates;

/** 指示动作,详见http://jira.huatugz.com:8139/pages/viewpage.action?pageId=13304481#id-地图数据接口文档（v1.08）-2.4.3获取路径规划-公共交通信息 */
@property (nonatomic, assign)         int sign;

//地图（建筑）id。当规划路径中含室外部分时，floorId=0的统一归为室外路径，即mapId为nil
@property (nonatomic, nullable, copy) NSString *mapID;

//楼层id
@property (nonatomic, nullable, copy) NSString *floorID;
@end




@interface HTMPTBus : NSObject<NSCopying, NSCoding>

//公交路段列表
@property (nonatomic, copy) NSArray<HTMPTBusLine *> *busLines;
@end




@interface HTMPTBusLine : NSObject<NSCopying, NSCoding>

//此段起乘站信息
@property (nonatomic, strong) HTMPTBusLineStop *departureStop;

//此段下车站信息
@property (nonatomic, strong) HTMPTBusLineStop *arrivalStop;

//线路信息
@property (nonatomic, strong) HTMPTRouteInfo *routeInfo;

//该段线路距离，单位为米。保留1位小数
@property (nonatomic, assign) double distance;

//该段路预计时间，单位为毫秒
@property (nonatomic, assign) NSUInteger duration;

//该段路坐标数组，[[lng,lat],....]
@property (nonatomic, copy)   NSArray<NSArray<NSNumber *> *> *coordinates;

//该段路途径公交站数
@property (nonatomic, assign) NSInteger viaNum;

//该段路途经公交站点列表
@property (nonatomic, copy)   NSArray<HTMPTBusLineStop *> *viaStops;
@end




@interface HTMPTPlace : NSObject<NSCopying, NSCoding>

//名称
@property (nonatomic, copy) NSString *name;

//位置坐标，lng,lat
@property (nonatomic, copy) NSString *location;

//城市id
@property (nonatomic, copy) NSString *cityId;

//城市名称
@property (nonatomic, copy) NSString *cityName;

@end




@interface HTMPTBusLineStop : HTMPTPlace<NSCopying, NSCoding>
@end




@interface HTMPTRouteInfo : NSObject<NSCopying, NSCoding>

//公交路线名称
@property (nonatomic, copy)   NSString *name;

//公交类型 0：公交 1：地铁
@property (nonatomic, assign) int type;

//首班车时间    格式如：0600，代表06：00
@property (nonatomic, nullable, copy)   NSString *startTime;

//末班车时间    格式如：2300，代表23：00
@property (nonatomic, nullable, copy)   NSString *endTime;

//首站名称
@property (nonatomic, copy)   NSString *startStopName;

//尾站名称
@property (nonatomic, copy)   NSString *endStopName;
@end




@interface HTMPTEntrance : HTMPTPlace<NSCopying, NSCoding>

/** 轮椅通行等级
wheelchair=unknown（未知，灰色，允许通行）
wheelchair=yes  (1级，绿色，优先通行）
wheelchair=limited  (2级，黄色，一般通行。部分通行，需要人协助）
wheelchair=no (3级，红色，禁止通行） */
@property (nonatomic, nullable, copy) NSString *wheelchair;
@end




@interface HTMPTRailway : NSObject<NSCopying, NSCoding>

//该路径总时长，单位为毫秒
@property (nonatomic, assign) NSUInteger duration;

//线路名称
@property (nonatomic, copy)   NSString *name;

//线路首站名称
@property(nonatomic, copy) NSString *startStopName;

//线路尾站名称
@property(nonatomic, copy) NSString *endStopName;

//线路车次号
@property (nonatomic, copy)   NSString *trip;

//该路径总长，单位为米。保留1位小数
@property (nonatomic, assign) double distance;

//线路车次类型，如：G字头的高铁火车
@property (nonatomic, copy)   NSString *type;

//火车始发站信息
@property (nonatomic, strong) HTMPTRailwayStop *departureStop;

//火车到站信息
@property (nonatomic, strong) HTMPTRailwayStop *arrivalStop;

//该段路途径站数
@property (nonatomic, assign) NSInteger viaNum;

//途径站点
@property (nonatomic, copy)   NSArray<HTMPTRailwayStop *> *viaStops;

//仓位及价格信息
@property (nonatomic, copy)   NSArray<HTMPTSpace *> *spaces;
@end



@interface HTMPTRailwayStop : HTMPTPlace<NSCopying, NSCoding>

//发车或到站时间，作为到站时间时，如大于24:00,表示跨天
@property (nonatomic, copy)             NSString *time;

//是否始发站，1表示为始发站，0表示非始发站
@property (nonatomic, nullable, strong) NSNumber *start;

//是否为终点站，1表示为终点站，0表示非终点站
@property (nonatomic, nullable, strong) NSNumber *end;

//途径站点的停靠时间，单位：分钟
@property (nonatomic, nullable, strong) NSNumber *wait;
@end



@interface HTMPTSpace : NSObject<NSCopying, NSCoding>

//仓位级别，如特等座
@property (nonatomic, copy) NSString *code;

//价格
@property (nonatomic, assign) double cost;
@end




NS_ASSUME_NONNULL_END
