//
//  ViewController.h
//  IndoorMapDemo
//
//  Created by Xd Huang on 2019/1/28.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IndoorMapFramework/HTMSearchAPI.h>
#import <IndoorMapFramework/HTMIndoorMapView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ViewController : UIViewController

@property (strong, nonatomic) HTMSearchAPI* searchAPI;
@property (strong,nonatomic) HTMIndoorMapView* indoorMapView;
@end

NS_ASSUME_NONNULL_END
