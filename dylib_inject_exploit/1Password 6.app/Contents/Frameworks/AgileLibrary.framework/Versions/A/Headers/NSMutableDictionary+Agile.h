//
//  NSMutableDictionary+AWS.h
//  BrowserPlugins
//
//  Created by Roustem Karimov on 8/29/07.
//  Copyright 2007 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (Agile) 
- (NSMutableDictionary *)ag_removeNSNullValues;
- (void)ag_setObject:(id)object forKey:(id)key;
@end
