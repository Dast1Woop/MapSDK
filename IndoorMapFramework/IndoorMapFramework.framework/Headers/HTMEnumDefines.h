//
//  HTEnumDefines.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/3/18.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    BY_TIME = 1,//时间优先,路径规划算法默认使用时间优先
    
    BY_DISTANCE,
    BY_STAIR,//楼梯优先
    BY_ESCALATOR,//自动扶梯优先
    BY_ELEVATOR,//电梯优先
    BY_WALK,//(步行优先)
    BY_DRIVE,//(行车优先) 【暂不支持】
    
    BY_ACCESSIBILITY,//无障碍优先
    BY_ACCESSIBILITY_ONLY,//仅无障碍通行
    
    BY_BLIND,// (盲道优先)
    BY_BLIND_ONLY,//仅盲道通行
    
    BY_WHEELCHAIR, // ( 通道优先) new
    BY_WHEELCHAIR_ONLY, // (仅轮椅通道通行) new
    
    //注:优先策略不一定完全经过无障碍、盲道等。建议使用仅无障碍、仅盲道通行
}RoutePlanType;

NS_ASSUME_NONNULL_BEGIN

@interface HTMEnumDefines : NSObject

@end

NS_ASSUME_NONNULL_END
