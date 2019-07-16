//
//  HTMSearchAPI.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/6/21.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HTMRouteSearchRequest;
@class HTMRouteSearchResponse;

@class HTMPOISearchRequestByID;
@class HTMPOISearchRequestByLocation;
@class HTMPOISearchResponse;

@protocol HTMSearchDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 搜索接口管理器
 */
@interface HTMSearchAPI : NSObject

/**
 实现了 `HTMSearchDelegate` 协议的对象指针
 */
@property (nonatomic, weak) id<HTMSearchDelegate> delegateCustom;

///**
// * @brief 建筑物查询接口
// * @param request 查询选项。具体属性字段请参考 `HTMBuildingSearchRequest` 类。
// */
//- (void)HTMBuildingSearch:(HTMBuildingSearchRequest *)request;

/**
 * @brief POI分类查询接口
 * @param request 查询选项。具体属性字段请参考 `HTMPOISearchRequestByID` 类。
 */
//- (void)HTMPoiCategorySearch:(HTMPoiSearchRequest *)request;

/**
 * @brief 根据地图id或区域id查询POI信息
 * @param request 查询选项。具体属性字段请参考 `HTMPOISearchRequestByID` 类。
 */
- (void)HTMPOISearchByID:(HTMPOISearchRequestByID *)request;

/**
 * @brief 根据地图id或区域id查询POI信息
 * @param request 查询选项。具体属性字段请参考 `HTMPOISearchRequestByID` 类。
 */
- (void)HTMPOISearchByLocation:(HTMPOISearchRequestByLocation *)request;

/**
 * @brief 路线查询接口
 * @param request 查询选项。具体属性字段请参考 `HTMRouteSearchRequest` 类。
 */
- (void)HTMRouteSearch:(HTMRouteSearchRequest *)request;

@end



/**
 HTMSearchDelegate协议，定义了搜索结果的回调方法，及发生错误时的回调方法。
 */
@protocol HTMSearchDelegate <NSObject>

@optional

/**
 * @brief 请求错误回调方法
 * @param request 查询选项。
 * @param error 错误信息。
 */
- (void)HTMSearchRequest:(id)request didFailWithError:(NSError *)error;

///**
// * @brief 建筑查询回调方法
// * @param request 查询选项。具体属性字段请参考 `HTMBuildingSearchRequest` 类。
// * @param response 查询结果。具体属性字段请参考 `HTMBuildingSearchResponse` 类。
// */
//- (void)onBuildingSearchDone:(HTMBuildingSearchRequest *)request response:(HTMBuildingSearchResponse *)response;

/**
 * @brief POI分类查询回调方法
 * @param request 查询选项。具体属性字段请参考 `HTMPoiSearchRequest` 类。
 * @param response 查询结果。具体属性字段请参考 `HTMPoiSearchResponse` 类。
 */
//- (void)onPOICategorySearchDone:(HTMPoiSearchRequest *)request response:(HTMPoiSearchResponse *)response;

/**
 * @brief POI查询回调方法
 * @param request 查询选项。具体属性字段请参考 `HTMPOISearchRequestByID` 类。
 * @param response 查询结果。具体属性字段请参考 `HTMPOISearchResponse` 类。
 */
- (void)onPOISearchDone:(id)request response:(HTMPOISearchResponse *)response;

/**
 * @brief 路线回调方法
 * @param request 查询选项。具体属性字段请参考 `HTMRouteSearchRequest` 类。
 * @param response 查询结果。具体属性字段请参考 `HTMRouteSearchResponse` 类。
 */
- (void)onRouteSearchDone:(HTMRouteSearchRequest *)request response:(HTMRouteSearchResponse *)response;


@end

NS_ASSUME_NONNULL_END
