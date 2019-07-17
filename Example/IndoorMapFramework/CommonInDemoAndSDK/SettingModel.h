//
//  SettingModel.h
//  HTMMapDemo
//
//  Created by LongMa on 2019/7/10.
//  Copyright © 2019 hautu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SettingModel : NSObject

@property(nonatomic, copy) NSString *gStr4Title;

@property (nonatomic, assign) BOOL gIsSelected;

+ (instancetype)modelWithTitle:(NSString *)title;
+ (instancetype)modelWithTitle:(NSString *)title isSelected:(BOOL)isSlted;
@end

NS_ASSUME_NONNULL_END
