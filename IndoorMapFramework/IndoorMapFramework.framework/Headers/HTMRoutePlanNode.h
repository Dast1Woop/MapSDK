//
//  RoutePlanNode.h
//  IndoorMapFramework
//
//  Created by Xd Huang on 2019/2/22.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HTMGeoCoor.h"

NS_ASSUME_NONNULL_BEGIN

@interface HTMRoutePlanNode : HTMGeoCoor

/** 名称 */
@property(nonatomic, copy) NSString *name;

/** mapID */
@property(nonatomic, copy) NSString *mapId;

- (instancetype)initWithLng:(double)lng lat:(double)lat;
+ (instancetype)nodeWithLng:(double)lng lat:(double)lat;

+ (instancetype)nodeWithLng:(double)lng
                        lat:(double)lat
                    floorID:(int)floorID
                       name:(NSString *)name
                      mapId:(NSString *)mapId;
@end

NS_ASSUME_NONNULL_END
