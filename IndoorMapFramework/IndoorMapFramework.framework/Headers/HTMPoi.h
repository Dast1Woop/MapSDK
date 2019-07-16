//
//  HTMPoi.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/12.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMGeoCoor;

NS_ASSUME_NONNULL_BEGIN

/** poi类别 ,后台返回数据有限，暂时与HTMFeature分开区分*/
@interface HTMPoi : NSObject

/** 唯一id */
@property(nonatomic, copy) NSString *idCustom;

///  POI点名称
@property(nonatomic, copy) NSString *name;

/// 坐标模型
@property(nonatomic, strong) HTMGeoCoor *geoCoor;

/** 地图模型类别 */
@property(nonatomic, copy) NSString *type;

/// POI点简介
@property(nonatomic, copy) NSString *descriptionCustom;

/** 类别分类-大类 */
@property(nonatomic, copy) NSString *bigCategory;

/** 类别分类-中类 */
@property(nonatomic, copy) NSString *midCategory;

/** 类别分类-小类 */
@property(nonatomic, copy) NSString *subCategory;

/// POI点与当前位置距离(根据当前位置获取POI信息时，会有值)
@property (nonatomic, assign) double distance;

@end

NS_ASSUME_NONNULL_END
