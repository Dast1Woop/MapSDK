//
//  ViewController.m
//  IndoorMapDemo
//
//  Created by Xd Huang on 2019/1/28.
//  Copyright © 2019 huatu. All rights reserved.
//

#import "ViewController.h"
#import <IndoorMapFramework/IndoorMapFramework.h>
#import <SVProgressHUD.h>
#import <Masonry.h>
#import "SettingModel.h"
#import "HTMSettingCollectionViewCell.h"

#define HTSCREEN_WIDTH  [UIScreen mainScreen].bounds.size.width
#define HTSCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#define KPERCENT_SETTING_COLLECTIONVIEW_OF_SCREEN 0.28

static NSString *const KREUSE_ID_COLLECTION_VIEW_CELL = @"HTMSettingCollectionViewCell";

@interface ViewController ()
<HTMSearchDelegate
,HTMIndoorMapDelegate
,MGLMapViewDelegate,
UICollectionViewDelegate,
UICollectionViewDataSource,
UICollectionViewDelegateFlowLayout
>


///奇数次点击，确定为起点；偶数次点击，确认为终点
@property (nonatomic, assign) BOOL gIsOddClick;

///导航起点
@property(nonatomic, strong) HTMRoutePlanNode *gStartNode;

///导航终点
@property(nonatomic, strong) HTMRoutePlanNode *gEndNode;

///路径搜索请求
@property(nonatomic, strong) HTMRouteSearchRequest *gRqst4RouteSearch;

///设置CollectionView数据源
@property (nonatomic, copy) NSArray *gArr4SettingCollectionView;

///设置视图
@property(nonatomic, strong) UICollectionView *pCollectionView4Setting;

@end

int const KMARGIN = 10;
@implementation ViewController

#pragma mark -  lifecycle
- (void)viewDidLoad {
    [super viewDidLoad];
 
    [self setUpUI];
//    [self downloadRoadNet];
}

- (void)dealloc{
    NSLog(@"地图页挂了！");
    [SVProgressHUD dismiss];
}

#pragma mark -  life methods
- (void)setUpUI{
    self.view.backgroundColor = [UIColor whiteColor];
    [SVProgressHUD setMinimumDismissTimeInterval:2];
    
    [self pmy_addIndoorMapV];
    [self pmy_addSettingCollectionView];
}

#pragma mark -  private
- (void)pmy_addSettingCollectionView{
    UICollectionViewFlowLayout *lFlowLayout = [[UICollectionViewFlowLayout alloc] init];
    lFlowLayout.scrollDirection = UICollectionViewScrollDirectionVertical;
    lFlowLayout.itemSize = CGSizeMake(76, 50);
    lFlowLayout.minimumLineSpacing = 8;
    lFlowLayout.minimumInteritemSpacing = 8;
    
    lFlowLayout.sectionInset = UIEdgeInsetsMake(8, 8, 8, 8);
    
    //    lFlowLayout.headerReferenceSize = CGSizeMake(20, 20);
    //    lFlowLayout.footerReferenceSize = CGSizeMake(20, 20);
    
    UICollectionView *lCV = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:lFlowLayout];
    
    [self.view addSubview:lCV];
    [lCV mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(0);
        make.height.mas_equalTo(KPERCENT_SETTING_COLLECTIONVIEW_OF_SCREEN * HTSCREEN_HEIGHT);
        make.leading.trailing.mas_equalTo(0);
    }];
    lCV.backgroundColor = UIColor.whiteColor;
    
    //滚动条闪烁5次，暗示设置视图可滑动
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self.view bringSubviewToFront:lCV];
        [lCV flashScrollIndicators];
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self.view bringSubviewToFront:lCV];
            [lCV flashScrollIndicators];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    
                    [self.view bringSubviewToFront:lCV];
                    [lCV flashScrollIndicators];
                    
                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                        [self.view bringSubviewToFront:lCV];
                        [lCV flashScrollIndicators];
                    });
                });
                [self.view bringSubviewToFront:lCV];
                [lCV flashScrollIndicators];
            });
        });
    });
    
    lCV.delegate = self;
    lCV.dataSource = self;
    
    [lCV registerNib:[UINib nibWithNibName:@"HTMSettingCollectionViewCell" bundle:[NSBundle mainBundle]] forCellWithReuseIdentifier:KREUSE_ID_COLLECTION_VIEW_CELL];
    self.pCollectionView4Setting = lCV;
    
}

- (void)pmy_addLocateBtn{
    UIButton *btn = [[UIButton alloc] init];
    [self.view addSubview:btn];
    
    [btn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(10);
        make.width.height.mas_equalTo(44);
        make.bottom.mas_equalTo(-44);
    }];
    
    [btn setTitle:@"定位" forState:UIControlStateNormal];
    btn.backgroundColor = [UIColor orangeColor];
//    [btn addTarget:self action:@selector(pmy_locateBtnDidClick:) forControlEvents:UIControlEventTouchUpInside];
}

//     1 -> "2380EFC1992749A28DCDC1A51F103A56"//宏泰
//     2 -> "7832DBD7585D44E48B98948BC17DC2BC"//国展带展位
//     3 -> "85F29ACC9C2743879B68B1D28540D03C"//鄣吴
//     4 -> "51F480C186374896BA676912ED00B041"//国展不带展位
- (void)pmy_addIndoorMapV{
    [self pmy_initMapView];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSError *lErr = nil;
//        [self.indoorMapView selectFloor:@"F2" error:&lErr];
        if (lErr) {
            [SVProgressHUD showErrorWithStatus:[NSString stringWithFormat:@"%@",lErr.localizedDescription]];
        }
    });
    
//警告：mapview的代码在sdk外被重写，导致sdk内地图加载成功、失败、缩放代理回调不执行怎么办？改为多代理模式。外界指定代理必须加到多代理对象的代理数组上。写法如下：
    self.indoorMapView.delegateCustom = self;
    [self.indoorMapView.mapView addMultiDelegate:self];
    
    self.indoorMapView.mapView.showsUserLocation = YES;
    [self.indoorMapView.mapView setCenterCoordinate:CLLocationCoordinate2DMake(23.176388, 113.411635)//宏泰
                                          zoomLevel:16
                                           animated:YES];
//    self.indoorMapView.isHidePointAnnotationWhenTapMap = YES;
}

- (void)pmy_initMapView{
    self.indoorMapView = [[HTMIndoorMapView alloc] init];
    [self.view addSubview:self.indoorMapView];
    
//    self.indoorMapView = [[HTMIndoorMapView alloc] initWithFrame:self.view.bounds];
//    self.indoorMapView.frame = CGRectMake(0, 44, self.view.bounds.size.width, self.view.bounds.size.height);
    [self.indoorMapView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.mas_equalTo(0);
        make.top.mas_equalTo(KPERCENT_SETTING_COLLECTIONVIEW_OF_SCREEN * HTSCREEN_HEIGHT);
        make.bottom.mas_equalTo(0);
    }];
}

-(void)p_restartRoutePlanWithType:(RoutePlanType)type{
    if (self.indoorMapView.isRoutePathShowing) {
        [self.indoorMapView clearRoutePath];
        self.gRqst4RouteSearch.planType = type;
        [self.searchAPI HTMRouteSearch:self.gRqst4RouteSearch];
        return;
    }
    
    //没有正在显示的路径
    if (self.gStartNode && self.gEndNode && self.gRqst4RouteSearch) {
        self.gRqst4RouteSearch.planType = type;
        [self.searchAPI HTMRouteSearch:self.gRqst4RouteSearch];
    }
}

#pragma mark -  events

#pragma mark -  dataSource 4 setting collection View
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return self.gArr4SettingCollectionView.count;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    return [self.gArr4SettingCollectionView[section] count];
}

-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    HTMSettingCollectionViewCell *lCell = [collectionView dequeueReusableCellWithReuseIdentifier:KREUSE_ID_COLLECTION_VIEW_CELL forIndexPath:indexPath];
    
    lCell.gLbl4Title.text = [self.gArr4SettingCollectionView[indexPath.section][indexPath.row] gStr4Title];
    
    return lCell;
}


//to try
//- (void)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(nonnull NSString *)kind atIndexPath:(nonnull NSIndexPath *)indexPath{
//
//}

#pragma mark -  UICollectionViewDelegateFlowLayout
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath{
    SettingModel *lM = self.gArr4SettingCollectionView[indexPath.section][indexPath.row];
    CGFloat lH = 44;
    CGRect lRect = [lM.gStr4Title boundingRectWithSize:CGSizeMake(CGFLOAT_MAX, lH)
                         options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)
                      attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:13]}
                         context:nil];
    CGFloat lWidth = MAX(50, ceil(lRect.size.width + 6));
    CGSize lSize = CGSizeMake(lWidth, lH);
//    NSLog(@"lSize:%@", NSStringFromCGSize(lSize));
    return lSize;
}

#pragma mark -  delegate 4 setting collection View
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    NSLog(@"collectionView indexPath：%@", indexPath);
    SettingModel *lM = self.gArr4SettingCollectionView[indexPath.section][indexPath.row];
    NSString *lTitle= lM.gStr4Title;
    
    //第0组:地点选择组
    if (0 == indexPath.section) {
        if ([lTitle isEqualToString:@"显示上海国展"]) {
            CLLocationCoordinate2D lCenter = CLLocationCoordinate2DMake(31.1900577584,121.2991090340);
            
            double lZoomLvL = 13.8;
            [self.indoorMapView.mapView setCenterCoordinate:lCenter zoomLevel:lZoomLvL animated:YES];
        }else if ([lTitle isEqualToString:@"显示彰吴小镇"]) {
            CLLocationCoordinate2D lCenter = CLLocationCoordinate2DMake(30.779956940496248,119.54307828322214);
            
            double lZoomLvL = 13;
            [self.indoorMapView.mapView setCenterCoordinate:lCenter zoomLevel:lZoomLvL animated:YES];
        }else if ([lTitle isEqualToString:@"显示宏泰智慧谷"]) {
            CLLocationCoordinate2D lCenter = CLLocationCoordinate2DMake(23.176180590014511, 113.41150059665102);
            
            double lZoomLvL = 17;
            [self.indoorMapView.mapView setCenterCoordinate:lCenter zoomLevel:lZoomLvL animated:YES];
        }else{//@“定位”
            self.indoorMapView.mapView.userTrackingMode = MGLUserTrackingModeFollow;
        }
    }else if (1 == indexPath.section) {
        if ([lTitle isEqualToString:@"显示/隐藏盲道"]) {
            lM.gIsSelected = !lM.gIsSelected;
            if (lM.gIsSelected) {
                [self.indoorMapView showBlindRoad];
            }else{
                [self.indoorMapView hideBlindRoad];
            }
        }else if([lTitle isEqualToString:@"显示/隐藏轮椅"]){
            lM.gIsSelected = !lM.gIsSelected;
            if (lM.gIsSelected) {
                [self.indoorMapView showWheelChairRoad];
            }else{
                [self.indoorMapView hideWheelChairRoad];
            }
        }else if([lTitle isEqualToString:@"显示/隐藏定位点"]){
            lM.gIsSelected = !lM.gIsSelected;
            if (lM.gIsSelected) {
                [self.indoorMapView.mapView setShowsUserLocation:YES];
            }else{
                [self.indoorMapView.mapView setShowsUserLocation:NO];
            }
        }else if([lTitle isEqualToString:@"显示/隐藏指南针"]){
            lM.gIsSelected = !lM.gIsSelected;
            if (lM.gIsSelected) {
                self.indoorMapView.mapView.compassView.hidden = YES;
            }else{
                self.indoorMapView.mapView.compassView.hidden = NO;
            }
        }else if([lTitle isEqualToString:@"隐藏楼层选择器"]){
            self.indoorMapView.floorPickerView.hidden = YES;
        }else if([lTitle isEqualToString:@"清除地图MARK"]){
            [self.indoorMapView clearAllPointAnnotations];
        }else if([lTitle isEqualToString:@"关键字搜索"]){
            [SVProgressHUD showWithStatus:@"关键字搜索中"];
            HTMPOISearchRequestByID *lRqstByRegionID = [[HTMPOISearchRequestByID alloc] init];
            //    lRqstByRegionID.regionId = @"156330523";
            lRqstByRegionID.mapId = self.indoorMapView.buildingIDMapShowing;
            lRqstByRegionID.pageNum = 1;
            lRqstByRegionID.pageSize = 10;
            lRqstByRegionID.keyword = @"洗手间";
            [self.searchAPI HTMPOISearchByID:lRqstByRegionID];
            
//            HTMPOISearchRequestByLocation *lRqstByLocation = [[HTMPOISearchRequestByLocation alloc] init];
//            HTMGeoCoor *lCoor = [[HTMGeoCoor alloc] init];
//            lRqstByLocation.pageNum = 1;
//            lRqstByLocation.pageSize = 10;
//            lCoor.lng = 119.5408207660144;
//            lCoor.lat = 30.77772023017141;
//            lRqstByLocation.crtGeoCoor = lCoor;
//            lRqstByLocation.meter = 500;
//            lRqstByRegionID.keyword = @"洗手间";
//            [self.searchAPI HTMPOISearchByLocation:lRqstByLocation];
        }else if([lTitle isEqualToString:@"类别搜索"]){
            [SVProgressHUD showWithStatus:@"类别搜索中"];
            HTMPOICategorySearchRequest *lRes = [[HTMPOICategorySearchRequest alloc] init];
            lRes.buildingID = self.indoorMapView.buildingIDMapShowing;
            [self.searchAPI HTMPoiCategorySearch:lRes];
        }else if([lTitle isEqualToString:@"取消模型选中效果"]){
            [self.indoorMapView resetAllFeaturesColor];
        }
        else{
            
        }
    }else{//第2组：路径规划组
        if ([lTitle isEqualToString:@"时间优先"]) {
            [self p_restartRoutePlanWithType:BY_TIME];
        }else if([lTitle isEqualToString:@"距离优先"]){
            [self p_restartRoutePlanWithType:BY_DISTANCE];
        }else if([lTitle isEqualToString:@"楼梯优先"]){
            [self p_restartRoutePlanWithType:BY_STAIR];
        }else if([lTitle isEqualToString:@"扶梯优先"]){
            [self p_restartRoutePlanWithType:BY_ESCALATOR];
        }else if([lTitle isEqualToString:@"电梯优先"]){
            [self p_restartRoutePlanWithType:BY_ELEVATOR];
        }else if([lTitle isEqualToString:@"步行优先"]){
            [self p_restartRoutePlanWithType:BY_WALK];
        }else if([lTitle isEqualToString:@"无障碍优先"]){
            [self p_restartRoutePlanWithType:BY_ACCESSIBILITY];
        }else if([lTitle isEqualToString:@"仅盲道通行"]){
            [self p_restartRoutePlanWithType:BY_BLIND_ONLY];
        }else{
            [self p_restartRoutePlanWithType:BY_TIME];
        }
    }
    
}

#pragma mark -  delegate 4 indoorMapView
- (void)htmIndoorMapViewDidFinishLoading:(HTMIndoorMapView *)indoorMapView{
    NSLog(@"IndoorViewController didFinishLoading ");
    
    [SVProgressHUD showSuccessWithStatus:@"地图加载成功"];

    //地图移到上海国展
    CLLocationCoordinate2D lCenter = CLLocationCoordinate2DMake(31.1900577584,121.2991090340);
    
    double lZoomLvL = 13.8;
    [self.indoorMapView.mapView setCenterCoordinate:lCenter zoomLevel:lZoomLvL animated:YES];
}

-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView floorDidSelected:(HTMFloorConfig *)floor{
    NSLog(@"IndoorViewController selectFloor %@",floor);
}

-(void)htmIndoorMapView:(HTMIndoorMapView *)indoorMapView
featureOrMapDidSelected:(MGLPolygonFeature * _Nullable)feature
              isFeature:(BOOL)isFeature
            featureCoor:(CLLocationCoordinate2D)coor{
    NSLog(@"IndoorViewController selectFeature %@",feature);

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        NSString *lName = @"小学";
//        [self.poiQuery queryPOIByName:lName];
//        [self.poiQuery queryPOIByCategoryType:@"100008"];
    });
    
    
    self.gIsOddClick = !self.gIsOddClick;
    
    if(self.gIsOddClick){
        [self.indoorMapView clearRoutePath];
        
        [self.indoorMapView clearAllPointAnnotations];
        [self.indoorMapView addOnePointAnnotationToMapViewWithCoor:coor];
        
        self.gStartNode.lng = [[feature attributeForKey:@"lng"] doubleValue];
        self.gStartNode.lat = [[feature attributeForKey:@"lat"] doubleValue];
        self.gStartNode.floorID =  [[feature attributeForKey:@"floorId"] intValue];
        
        self.gRqst4RouteSearch.fromMapId = [feature attributeForKey:@"mapId"];
        self.gRqst4RouteSearch.fromGeoCoor = self.gStartNode;
        
    }else{
        self.gEndNode.lng = [[feature attributeForKey:@"lng"] doubleValue];
        self.gEndNode.lat = [[feature attributeForKey:@"lat"] doubleValue];
        self.gEndNode.floorID =  [[feature attributeForKey:@"floorId"] intValue];
        
        self.gRqst4RouteSearch.toMapId = [feature attributeForKey:@"mapId"];
        self.gRqst4RouteSearch.toGeoCoor = self.gEndNode;
        
        [SVProgressHUD showWithStatus:@"规划路线中"];
        self.gRqst4RouteSearch.lang = @"zh_cn";
        
        self.gRqst4RouteSearch.planType = BY_TIME;
        [self.searchAPI HTMRouteSearch:self.gRqst4RouteSearch];
    }
}

#pragma mark -  delegate search
- (void)HTMSearchRequest:(id)request didFailWithError:(NSError *)error{
    NSLog(@"error = %@", error.localizedDescription);
    NSString *lStr = @"搜索失败";
    if (error) {
        if ([request isKindOfClass:[HTMRouteSearchRequest class]]) {
            lStr = @"路径规划失败";
        }else if([request isKindOfClass:[HTMPOISearchRequestByID class]]){
            lStr = @"通过区域id搜索失败";
        }else if([request isKindOfClass:[HTMPOISearchRequestByLocation class]]){
            lStr = @"通过位置搜索失败";
        }else if([request isKindOfClass:[HTMPOICategorySearchRequest class]]){
            lStr = @"类别搜索失败";
        }else{//others
            
        }
    }
    
    [SVProgressHUD showErrorWithStatus:lStr];
}
- (void)onPOISearchDone:(id)request response:(HTMPOISearchResponse *)response{
    if ([request isKindOfClass:[HTMPOISearchRequestByID class]]) {
        HTMPOISearchRequestByID *lRequest = (HTMPOISearchRequestByID *)request;
        NSString *lMsg = [NSString stringWithFormat:@"搜索成功，共%zd个%@,详见Xcode log",response.poisArr.count, lRequest.keyword];
        [SVProgressHUD showSuccessWithStatus:lMsg];
        NSLog(@"通过id+关键字搜索成功,response.poisArr = %@, request:%@", response.poisArr, request);
    }else if([request isKindOfClass:[HTMPOISearchRequestByLocation class]]){
        HTMPOISearchRequestByLocation *lRequest = (HTMPOISearchRequestByLocation *)request;
        NSString *lMsg = [NSString stringWithFormat:@"搜索成功，共%zd个%@,详见Xcode log",response.poisArr.count, lRequest.keyword];
        [SVProgressHUD showSuccessWithStatus:lMsg];
        NSLog(@"通过位置+关键字搜索成功,response.poisArr = %@, request:%@", response.poisArr, request);
    }
}

- (void)onPOICategorySearchDone:(HTMPOICategorySearchRequest *)request response:(HTMPOICategorySearchResponse *)response{
    NSString *lMsg = [NSString stringWithFormat:@"类别搜索成功，当前地图共%zd个类别,详见Xcode log",response.poiCategoriesArr.count];
    [SVProgressHUD showSuccessWithStatus:lMsg];
    NSLog(@"类别搜索成功，,response.poiCategoriesArr = %@", response.poiCategoriesArr);
}

- (void)onRouteSearchDone:(HTMRouteSearchRequest *)request response:(HTMRouteSearchResponse *)response{
    [SVProgressHUD showSuccessWithStatus:@"规划路线成功"];
    
    HTMRoutePaths *lRoutePaths = response.routePaths;
    for(HTMRoutePath* path in lRoutePaths.paths ){
        NSLog(@"routePlanDidFinished points  %@",path.pointsArr);
        for(HTMRoutePlanInstruction *instruction in path.instructions){
            NSLog(@"instruction: %@",instruction);
        }
    }
    
    //大多只有一个结果
    if(lRoutePaths.paths.count > 0 ){
       NSError *lErr = [self.indoorMapView showRoutePath:lRoutePaths.paths.firstObject];
        if (lErr) {
            NSString *lMsg = [NSString stringWithFormat:@"画线失败：%@",lErr.localizedDescription];
            [SVProgressHUD showErrorWithStatus:lMsg];
        }
    }
}

#pragma mark -  delegate 4 mapbox
- (void)mapView:(MGLMapView *)mapView regionDidChangeAnimated:(BOOL)animated{
    NSLog(@"sdk外 regionDidChangeAnimated");
}

#pragma mark -  getter & setter.
- (HTMRoutePlanNode *)gStartNode{
    if(nil == _gStartNode){
        _gStartNode = [[HTMRoutePlanNode alloc] init];
    }
    return _gStartNode;
}

- (HTMRoutePlanNode *)gEndNode{
    if(nil == _gEndNode){
        _gEndNode = [[HTMRoutePlanNode alloc] init];
    }
    return _gEndNode;
}

- (HTMSearchAPI *)searchAPI{
    if (nil == _searchAPI) {
        _searchAPI = [[HTMSearchAPI alloc] init];
        _searchAPI.delegateCustom = self;
    }
    return _searchAPI;
}

- (HTMRouteSearchRequest *)gRqst4RouteSearch{
    if (nil == _gRqst4RouteSearch) {
        _gRqst4RouteSearch = [[HTMRouteSearchRequest alloc] init];
    }
    return _gRqst4RouteSearch;
}

- (NSArray *)gArr4SettingCollectionView{
    if (nil == _gArr4SettingCollectionView) {
        
        _gArr4SettingCollectionView =
        @[
          @[[SettingModel modelWithTitle:@"定位"]
            ,[SettingModel modelWithTitle:@"显示上海国展"]
            ,[SettingModel modelWithTitle:@"显示彰吴小镇"]
            ,[SettingModel modelWithTitle:@"显示宏泰智慧谷"]
            ],
          @[[SettingModel modelWithTitle:@"隐藏楼层选择器"]
            ,[SettingModel modelWithTitle:@"显示/隐藏指南针"]
            ,[SettingModel modelWithTitle:@"显示/隐藏定位点"]
            ,[SettingModel modelWithTitle:@"清除地图MARK"]
            ,[SettingModel modelWithTitle:@"关键字搜索"]
            ,[SettingModel modelWithTitle:@"类别搜索"]
            ,[SettingModel modelWithTitle:@"显示/隐藏盲道"]
            ,[SettingModel modelWithTitle:@"显示/隐藏轮椅"]
            ,[SettingModel modelWithTitle:@"取消模型选中效果"]
            ],
          @[[SettingModel modelWithTitle:@"时间优先"]
            ,[SettingModel modelWithTitle:@"距离优先"]
            ,[SettingModel modelWithTitle:@"楼梯优先"]
            ,[SettingModel modelWithTitle:@"扶梯优先"]
            ,[SettingModel modelWithTitle:@"电梯优先"]
            ,[SettingModel modelWithTitle:@"步行优先"]
            ,[SettingModel modelWithTitle:@"无障碍优先"]
            ,[SettingModel modelWithTitle:@"仅盲道通行"]
//            ,@"仅无障碍通行"
//            ,@"盲道优先"
//            ,@"轮椅通道优先"
//            ,@"轮椅通道通行"
            ]
          ];
    }
    return _gArr4SettingCollectionView;
}

@end
