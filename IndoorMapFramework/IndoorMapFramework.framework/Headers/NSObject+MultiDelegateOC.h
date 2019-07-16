

#import <Foundation/Foundation.h>
#import "MultiDelegateOC.h"

/*
 Multi Delegate Extension
*/
@interface NSObject (MultiDelegateOC)

@property (readonly, nonatomic) MultiDelegateOC *multiDelegate;


- (void)addMultiDelegate:(id)delegate;
- (void)addDelegate:(id)delegate beforeDelegate:(id)otherDelegate;
- (void)addDelegate:(id)delegate afterDelegate:(id)otherDelegate;

- (void)removeMultiDelegate:(id)delegate;
- (void)removeAllDelegates;

@end
