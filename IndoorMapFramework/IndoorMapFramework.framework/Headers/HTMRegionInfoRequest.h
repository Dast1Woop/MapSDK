//
//  HTMRegionInfoRequest.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/12/26.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 根据区域编号获取区域信息
@interface HTMRegionInfoRequest : NSObject

//区域编号
@property(nonatomic, copy) NSString *code;

- (instancetype)initWithCode:(NSString *)code;
+ (instancetype)requestWithCode:(NSString *)code;
@end

NS_ASSUME_NONNULL_END
