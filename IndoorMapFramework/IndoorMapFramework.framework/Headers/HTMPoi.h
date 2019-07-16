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
@interface HTMPoi : NSObject

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

/// POI点与当前位置距离(根据当前位置获取POI信息时，会有值)
@property (nonatomic, assign) double distance;

@end

NS_ASSUME_NONNULL_END
