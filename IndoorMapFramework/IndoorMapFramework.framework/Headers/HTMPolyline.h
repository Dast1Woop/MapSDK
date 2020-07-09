//
//  HTMPolyline.h
//  IndoorMapFramework
//
//  Created by LongMa on 2020/7/9.
//  Copyright © 2020 huatu. All rights reserved.
//

#import <Mapbox/Mapbox.h>

NS_ASSUME_NONNULL_BEGIN

///拥挤程度，不同程度对应不同颜色画线
typedef enum{
    LINE_TYPE_CROWD_LEVEL_1,
    LINE_TYPE_CROWD_LEVEL_2,
    LINE_TYPE_CROWD_LEVEL_3,
    LINE_TYPE_CROWD_LEVEL_4,
    LINE_TYPE_CROWD_LEVEL_5,
    LINE_TYPE_CROWD_LEVEL_6,
}LINE_CROWD_LEVEL;

@interface HTMPolyline : MGLPolyline
@property (nonatomic, assign) LINE_CROWD_LEVEL crowdLevel;
@end

NS_ASSUME_NONNULL_END
