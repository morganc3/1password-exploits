//
//  NSObject+Agile.h
//  1Password
//
//  Created by RK on 10-02-16.
//  Copyright 2010 Agile Web Solutions Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject (Agile)

- (void)ag_setDelegate:(id)delegate forService:(NSString *)service;
- (void)ag_setValue:(id)value forName:(NSString *)name;
- (void)ag_validateAndPerformSelectorName:(NSString *)selectorName withObject:(id)object;
- (BOOL)ag_isFullyImplementingProtocol:(Protocol *)protocol;

@end
