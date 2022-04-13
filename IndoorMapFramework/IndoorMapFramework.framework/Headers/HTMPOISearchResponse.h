//
//  HTMPOISearchResponse.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMPoi;

NS_ASSUME_NONNULL_BEGIN

@interface HTMPOISearchResponse : NSObject<NSCopying,NSCoding>

///搜索到的poi模型数组，注意：数组长度 == pageSize  <= total(总记录数)。对于通过poiID搜索的情况，此数组中只有一个元素
@property (nonatomic, copy) NSArray<HTMPoi *> *poisArr;

//数据标签，默认为nil。floors指全部楼层数据
@property(nonatomic, copy) NSString *label;

//MARK: HTMPOISearchByID 或 HTMPOINewSearchByMultiCombine 方法请求的结果里有如下数据
///当前页码
@property (nonatomic,assign) int pageNum;

///每页记录数
@property (nonatomic,assign) int pageSize;

///总记录数 注意： 数据源为高德时，目前无法获取total，当无下一页时，total=0
@property (nonatomic,assign) int total;

///总页数
@property (nonatomic,assign) int pages;

@end

NS_ASSUME_NONNULL_END
