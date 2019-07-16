//
//  HTMRoadNetModel.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/28.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMRoadNetModel : NSObject

#pragma mark -  常用
@property(nonatomic, copy) NSString *startX;
@property(nonatomic, copy) NSString *startY;
@property(nonatomic, copy) NSString *endX;
@property(nonatomic, copy) NSString *endY;

/** 路宽 */
@property(nonatomic, copy) NSString *width;

/** 楼层名字 */
@property(nonatomic, copy) NSString *floorName;
@property(nonatomic, copy) NSString *version;

#pragma mark -  不常用
@property(nonatomic, copy) NSString *mapId;
@property(nonatomic, copy) NSString *mapName;
@property(nonatomic, copy) NSString *startZ;
@property(nonatomic, copy) NSString *startLog;
@property(nonatomic, copy) NSString *startLat;
@property(nonatomic, copy) NSString *endZ;
@property(nonatomic, copy) NSString *endLog;
@property(nonatomic, copy) NSString *endLat;
@property(nonatomic, copy) NSString *length;


@end

NS_ASSUME_NONNULL_END
