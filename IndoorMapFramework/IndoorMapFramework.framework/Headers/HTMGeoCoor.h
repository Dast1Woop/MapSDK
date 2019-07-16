//
//  HTMGeoCoor.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMGeoCoor : NSObject

/// 经度
@property (nonatomic, assign) double lng;

/// 纬度
@property (nonatomic, assign) double lat;

/// 楼层id
@property (nonatomic, assign) int floorID;

@end

NS_ASSUME_NONNULL_END
