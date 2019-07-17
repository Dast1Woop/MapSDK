//
//  HTMSettingCollectionViewCell.m
//  HTMMapDemo
//
//  Created by LongMa on 2019/7/12.
//  Copyright © 2019 hautu. All rights reserved.
//

#import "HTMSettingCollectionViewCell.h"

@interface HTMSettingCollectionViewCell ()

@end

@implementation HTMSettingCollectionViewCell

- (instancetype)initWithCoder:(NSCoder *)aDecoder{
    
    if (self = [super initWithCoder:aDecoder]) {
        //此时，_gLbl4Title为nil
//        _gLbl4Title.numberOfLines = 0;
//        _gLbl4Title.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:0.1];
//        _gLbl4Title.textAlignment = NSTextAlignmentCenter;
    
        self.contentView.layer.cornerRadius = 8;
        self.contentView.layer.masksToBounds = YES;
    }
    return  self;
}

@end
