//
//  HomeViewController.m
//  IndoorMapFramework
//
//  Created by LongMa on 2019/3/18.
//  Copyright © 2019 huatu. All rights reserved.
//

#import "HomeViewController.h"
#import "ViewController.h"

#define HTScreenWidth   [UIScreen mainScreen].bounds.size.width
#define HTScreenHeight  [UIScreen mainScreen].bounds.size.height

@interface HomeViewController ()

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setUpUI];
}

- (void)setUpUI{
    self.title = @"首页";
    
    UIButton *lBtn = [[UIButton alloc] init];
    [self.view addSubview:lBtn];
    
    CGFloat lWidth = 100;
    lBtn.frame = CGRectMake(0.5*(HTScreenWidth - lWidth), 0.5*HTScreenHeight, lWidth, 60);
    lBtn.backgroundColor = [UIColor blackColor];
    [lBtn setTitle:@"显示地图" forState:UIControlStateNormal];
    [lBtn addTarget:self action:@selector(btnDidClick:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)btnDidClick:(UIButton *)btn{
    ViewController *lVC = [[ViewController alloc] init];
    [self.navigationController pushViewController:lVC animated:YES];
}

@end
