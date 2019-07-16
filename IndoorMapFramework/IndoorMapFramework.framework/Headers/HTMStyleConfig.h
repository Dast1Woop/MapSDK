//
//  HTMStyleConfig.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/4.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMStyleConfig : NSObject

/** 地图初始比例 */
@property(nonatomic, strong) NSNumber *zoom;

/** 地图中心点经度 */
@property(nonatomic, strong) NSString *mapCenterLngStr;

/** 地图中心点纬度 */
@property(nonatomic, strong) NSString *mapCenterLatStr;


@end

NS_ASSUME_NONNULL_END
