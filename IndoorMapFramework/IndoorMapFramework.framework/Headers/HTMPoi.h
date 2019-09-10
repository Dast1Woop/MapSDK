//
//  HTMPoi.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/12.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMGeoCoor;
@class HTMPoiCategory;

NS_ASSUME_NONNULL_BEGIN

/** poi类别 */
@interface HTMPoi : NSObject<NSCopying, NSCoding>

/** 唯一id */
@property(nonatomic, copy) NSString *idCustom;

///  POI点名称
@property(nonatomic, copy) NSString *name;

/// 坐标模型
@property(nonatomic, strong) HTMGeoCoor *geoCoor;

///poi类别对象，里面包括type，bigCategory，midCategory，bigCategory属性
@property(nonatomic, strong) HTMPoiCategory *poiCategory;

/// POI点简介
@property(nonatomic, copy) NSString *descriptionCustom;

///状态：1为正常，2为维护，3为停用
@property (nonatomic, assign) int status;

///是否支持轮椅：null未知，yes可通行，limited一般通行，no禁止通行
@property(nonatomic, copy) NSString *wheelchair;

///营业时间
@property(nonatomic, copy) NSString *openingHours;

///联系电话
@property(nonatomic, copy) NSString *phone;

///地址
@property(nonatomic, copy) NSString *address;

/// POI点与当前位置距离(根据当前位置获取POI信息时，会有值)
@property (nonatomic, assign) double distance;

///现场图片 链接数组
@property(nonatomic, copy) NSArray<NSString *> *image;

///POI特殊类型：0时为不支持路径规划（不可点击），1时支持路径规划（可点击）
@property (nonatomic, assign) int group;

///更新时间
@property(nonatomic, copy) NSString *updateTime;

///poi样式
@property(nonatomic, copy) NSString *subclass;

///poi类型
@property(nonatomic, copy) NSString *mappingKey;

///所在层，名字/ID？
@property(nonatomic, copy) NSString *level;

///是否室内
@property(nonatomic, copy) NSString *indoor;

///权重
@property(nonatomic, copy) NSString *score;

///备注
@property(nonatomic, copy) NSString *note;

///室内poi所属建筑id
@property(nonatomic, copy) NSString *mapId;




@end

NS_ASSUME_NONNULL_END
