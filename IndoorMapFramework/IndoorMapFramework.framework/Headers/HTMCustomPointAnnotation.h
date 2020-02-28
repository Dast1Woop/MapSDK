//
//  HTMCustomPointAnnotation.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/10/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Mapbox/Mapbox.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMCustomPointAnnotation : MGLPointAnnotation

/// 图片链接地址，没有的话默认为nil
@property (nonatomic, copy) NSString *imageUrlStr;
@end

NS_ASSUME_NONNULL_END
