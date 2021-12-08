//
//  HTMSubFacility.h
//  IndoorMapFramework
//
//  Created by huatu on 2021/12/7.
//  Copyright © 2021 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 {
 "name": "文化中心停车场出入口",
 "subclass": "entrance",
 "lng": 119.926641,
 "lat": 30.01325,
 "score": 0,
 "wheelchair": "no",
 "status": 1,
 "subCategory": "无障碍出入口",
 "address": "浙江省杭州市富阳区鹿山街道江滨西大道",
 "osm_id": 471363,
 "mapping_key": "facility"
 }
 */

@interface HTMSubFacility : NSObject

@property(nonatomic, copy) NSString *name;

@property(nonatomic, copy) NSString *subclass;

@property (nonatomic, assign) double lat;

@property(nonatomic, assign) double lng;

@property(nonatomic, assign) NSInteger score;

@property(nonatomic, copy) NSString *wheelchair;

@property(nonatomic, assign) NSInteger status;

@property(nonatomic, copy) NSString *subCategory;

@property(nonatomic, copy) NSString *address;

@property(nonatomic, assign) NSInteger osm_id;

@property(nonatomic, copy) NSString *mapping_key;

@end

NS_ASSUME_NONNULL_END
