//
//  HTMAnnotationController.h
//  IndoorMapFramework
//
//  Created by LongMa on 2021/3/5.
//  Copyright © 2021 huatu. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HTMAutoVisibilityAnnotation;
#import <Mapbox/Mapbox.h>

@protocol HTMAutoVisibilityAnnotationControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface HTMAutoVisibilityAnnotationController : NSObject

/// 已添加大头针对象数组
@property (nonatomic,copy) NSArray<HTMAutoVisibilityAnnotation *> *gArr4Annotataions;

@property (nonatomic,weak) id<HTMAutoVisibilityAnnotationControllerDelegate> delegateCustom;

//MARK: methods
- (instancetype)initWithMapView:(MGLMapView *)mapView;

# pragma mark Adding, removing style annotations
/**
 Adds multiple style annotations to the `MGLMapView`.
 
 @param styleAnnotations An array of `HTMAutoVisibilityAnnotation`s that should be added to the `MGLMapView`.
 */
- (void)addStyleAnnotations:(NSArray<HTMAutoVisibilityAnnotation *> *)styleAnnotations;

/**
 Removes multiple style annotation from the `MGLMapView`.
 
 @param styleAnnotations An array of `HTMAutoVisibilityAnnotation`s that should be removed from the `MGLMapView`.
 */
- (void)removeStyleAnnotations:(NSArray <HTMAutoVisibilityAnnotation *> *)styleAnnotations;


@end

/**
 The `HTMAutoVisibilityAnnotationControllerDelegate` protocol defines a set of optional methods that you
 can use to receive updates to style annotation changes.
 */
@protocol HTMAutoVisibilityAnnotationControllerDelegate <NSObject>

@optional

/**
 Called after the user has tapped and selected a style annotation.
 
 @param styleAnnotation The annotation that was selected.
 */
- (void)annotationController:(HTMAutoVisibilityAnnotationController *)annotationController didSelectStyleAnnotation:(HTMAutoVisibilityAnnotation *)styleAnnotation;

/**
 Called after the user has tapped and deselected a style annotation.
 
 @param styleAnnotation The annotation that was deselected.
 */
- (void)annotationController:(HTMAutoVisibilityAnnotationController *)annotationController didDeselectStyleAnnotation:(HTMAutoVisibilityAnnotation*)styleAnnotation;

@end

NS_ASSUME_NONNULL_END
