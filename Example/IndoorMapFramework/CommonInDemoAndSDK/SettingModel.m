//
//  SettingModel.m
//  HTMMapDemo
//
//  Created by LongMa on 2019/7/10.
//  Copyright © 2019 hautu. All rights reserved.
//

#import "SettingModel.h"

@implementation SettingModel
+ (instancetype)modelWithTitle:(NSString *)title{
    return [self modelWithTitle:title isSelected:NO];
}

+ (instancetype)modelWithTitle:(NSString *)title isSelected:(BOOL)isSlted{
    SettingModel *lM = [[SettingModel alloc] init];
    
    lM.gStr4Title = title;
    lM.gIsSelected = isSlted;
    return lM;
}

@end
