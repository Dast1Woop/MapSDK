//
//  HTMFeature.h
//  IndoorMapFramework
//
//  Created by LongMa on 2019/4/11.
//  Copyright © 2019 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMGeometry;
NS_ASSUME_NONNULL_BEGIN

@interface HTMFeature : NSObject

//1级同名，无需指定对应关系
/** 楼层名字 */
@property(nonatomic, copy) NSString *floorName;

/** 经度 */
@property(nonatomic, assign) double lng;

/** 纬度 */
@property(nonatomic, assign) double lat;

/** feature的ID,数字类型的字符串不能超过16位数字 */
@property(nonatomic, copy) NSString *idCustom;

/** 名字 */
@property(nonatomic, copy) NSString *name;

/** 描述信息 */
@property (nonatomic, copy) NSString *desc;

/** 楼层id */
@property(nonatomic, assign) int floorId;

/** 所属类型 */
@property(nonatomic, copy) NSString *type;

/** 楼层的唯一id */
@property(nonatomic, assign) int mapFloorId;

/** 地图id */
@property(nonatomic, copy) NSString *mapId;

/** 图标的缩放倍数，必须大于等于0，默认为1 */
@property(nonatomic, copy) NSString *iconSize;

/** 文字显示的最小放大级别 */
@property(nonatomic, assign) int minZoom;

/** 文字显示的最大放大级别 */
@property(nonatomic, assign) int maxZoom;

/** 地图编辑器一个feature绑定一个主题时使用到的 */
@property(nonatomic, copy) NSString *styleId;

/** 文字显示的颜色，rgb十六进制，如“#000000” */
@property(nonatomic, copy) NSString *textColor;

/** 文字的光晕颜色，rgb十六进制，如“#000000” */
@property(nonatomic, copy) NSString *textHaloColor;

/** 文字光晕颜色的宽度，必须大于或等于0    单位：px */
@property(nonatomic, copy) NSString *textHaloWidth;

/** 文字从锚点处的偏移距离，正数表示文字向右移动，负数表示向左移动    单位：em */
@property(nonatomic, copy) NSString *textOffsetX;

/** 文字从锚点处的偏移距离，正数表示文字向下移动，负数表示向上移动    单位：em */
@property(nonatomic, copy) NSString *textOffsetY;

/** 文字的透明度 */
@property(nonatomic, copy) NSString *textOpacity;

/** 文字的字体大小 */
@property(nonatomic, copy) NSString *textSize;


@end

NS_ASSUME_NONNULL_END
