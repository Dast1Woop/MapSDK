//
//  HTMAutoVisibilityAnnotation.h
//  IndoorMapFramework
//
//  Created by LongMa on 2021/3/1.
//  Copyright © 2021 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <MGLSymbolStyleAnnotation.h>
@class MGLSymbolStyleAnnotation;
NS_ASSUME_NONNULL_BEGIN

@interface HTMAutoVisibilityAnnotation : NSObject

/// MGLSymbolStyleAnnotation类型的大头针对象
@property (nonatomic,strong) MGLSymbolStyleAnnotation *annoObj;

/// 楼层id
@property (nonatomic,assign) int floorIdInt;
@end

NS_ASSUME_NONNULL_END
