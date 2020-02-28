//
//  HTMRegionLocationResponse.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/9/9.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMRegionInfoResponse : NSObject<NSCoding, NSCopying>

//区域id
@property (nonatomic, copy)             NSString *idCustom;

//创建时间
@property (nonatomic, copy)             NSString *createTime;

//区域名称
@property (nonatomic, copy)             NSString *name;

//简称
@property (nonatomic, copy)             NSString *shortName;

//区域编号    1
@property (nonatomic, copy)             NSString *code;

//纬度
@property (nonatomic, assign)           double lat;

//经度
@property (nonatomic, assign)           double lng;

//地区级别：1国家，2省，3市，4区
@property (nonatomic, assign)           int level;

//父区域id
@property (nonatomic, copy)             NSString *parent;

/** 区域范围,eg:
"bbox": [
          112.953002,
          22.551699,
          114.05483199999999,
          23.932299999999998
      ] */
@property (nonatomic, copy)             NSArray<NSNumber *> *bbox;

//new 191226
//
/**区域边界，GeoJson数据。
eg:
 "geometry": {
    "coordinates": [
        [
            [
                [
                    113.656,
                    22.707
                ],
                [
                    113.656,
                    22.707
                ],
                [
                    113.656,
                    22.708
                ],
                [
                    113.656,
                    22.708
                ],
                [
                    113.656,
                    22.707
                ]
            ]
        ],
        [
            [
                [
                    113.647,
                    22.724
                ],
                [
                    113.647,
                    22.723
                ],
                [
                    113.647,
                    22.724
                ],
                [
                    113.647,
                    22.724
                ],
                [
                    113.647,
                    22.724
                ]
            ]
        ]
    ],
    "type": "MultiPolygon"
} */
@property (nonatomic, copy) NSDictionary *geometry;

//获取geometry对应的Json字符串
- (NSString *)getGeometryJsonString;


@end

NS_ASSUME_NONNULL_END



