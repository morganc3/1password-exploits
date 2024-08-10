//
//  NSMenu+AgileBits.h
//  OnePasswordOSX
//
//  Created by Roustem Karimov on 7/27/2013.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSMenu (AgileBits)

- (NSMenuItem *)ag_menuItemWithAction:(SEL)action;
- (void)hideDanglingSeparators;

@end
