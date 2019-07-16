//
//  IndoorDataConfig.h
//  IndoorMap
//
//  Created by Xd Huang on 2019/1/14.
//  Copyright © 2019 Xd Huang. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMStyleConfig;
@class HTMFloorConfig;

NS_ASSUME_NONNULL_BEGIN

@interface HTMIndoorConfig : NSObject

/** 用于指示当前地图数据一共有几个楼层 */
@property (nonatomic, copy) NSArray<HTMFloorConfig*> *floors;

/** 字符串，必不可少，用于本地化后，以url方式传递到mapbox相关接口 */
@property (nonatomic, copy) NSString *style;

/** 映射到 style对应字典，方便获取zoom和中心点坐标。与styleStr映射的其实是同一个字段，但是不同类型决定了MJ如何转换 */
@property (nonatomic, strong) HTMStyleConfig *styleCustomObj;
@end

NS_ASSUME_NONNULL_END
