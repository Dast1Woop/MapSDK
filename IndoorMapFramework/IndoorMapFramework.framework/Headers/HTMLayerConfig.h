//
//  LayerConfig.h
//  IndoorMap
//
//  Created by Xd Huang on 2019/1/14.
//  Copyright © 2019 Xd Huang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTMLayerConfig : NSObject

/** 图层类型，表示图层的类型。目前枚举数据：Floor（楼层）、Label（标签）、Navigation（路网）、BlindRoad（盲道） */
@property (nonatomic, copy) NSString *type;

/** 图层的数据类型，表示图层的数据类型。目前枚举数据：Polygon（多边形/面）、PolygonLine（多边形的边）、Point（点）、LineString（线段） */
@property (nonatomic, copy) NSString *dataType;

/** 图层数据源编号 */
@property (nonatomic, copy) NSString *source;

/** 图层编号 */
@property (nonatomic, copy) NSString *layerID;
@end

NS_ASSUME_NONNULL_END
