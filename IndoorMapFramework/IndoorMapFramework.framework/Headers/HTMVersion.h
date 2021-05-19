//
//  HTMVersion.h
//  IndoorMapFramework
//
//  Created by LongMa on 2021/5/19.
//  Copyright © 2021 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMVersion : NSObject

/// 版本（时间戳字符串），eg:@"202105191409",时间戳在每次编译时会自动生成
+ (NSString *)version;
@end

NS_ASSUME_NONNULL_END
