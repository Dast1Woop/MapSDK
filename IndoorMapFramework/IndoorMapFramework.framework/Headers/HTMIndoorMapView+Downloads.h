//
//  HTMIndoorMapView+Downloads.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/28.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <IndoorMapFramework/IndoorMapFramework.h>
@class HTMRoadNetModel;
NS_ASSUME_NONNULL_BEGIN

@interface HTMIndoorMapView (Downloads)
+ (void)getRoadNetInfoWithAreaID:(NSString *)areaID
                        progress:(void (^)(NSProgress * _Nonnull))downProgressBlcok
                    successBlcok:(void (^)(NSURLSessionDataTask *_Nonnull task, NSArray<HTMRoadNetModel *>* roadNetModelsArr))successBlcok
                    failureBlcok:(void (^)(NSURLSessionDataTask *_Nonnull task, NSError *error))failureBlcok;
@end

NS_ASSUME_NONNULL_END

