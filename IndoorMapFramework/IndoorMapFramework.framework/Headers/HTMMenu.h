//
//  HTMMenu.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/9/29.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMMenu : NSObject

///  唯一id
@property(nonatomic, copy) NSString *idCustom;

///  菜单code
@property(nonatomic, copy) NSString *menuCode;

/// 菜单内容
@property(nonatomic, copy) NSString *menuName;

// 显示名称
@property(nonatomic, copy) NSString *text;

/// 父类编号
@property(nonatomic, copy) NSString *parent;

/// 数据库中层级
@property (nonatomic, assign) int level;

/// 子菜单
@property(nonatomic, copy) NSArray<HTMMenu *> *children;

/// 图标地址
@property(nonatomic, copy) NSString *icon;

// 类别页信息
@property(nonatomic, strong)  HTMMenu *category;

// 首页信息
@property(nonatomic, strong)  HTMMenu *home;

@end

NS_ASSUME_NONNULL_END
