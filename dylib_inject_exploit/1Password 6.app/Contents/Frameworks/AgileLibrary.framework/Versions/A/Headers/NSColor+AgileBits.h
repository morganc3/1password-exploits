//
//  NSColor+AgileBits.h
//  OnePasswordOSX
//
//  Created by Roustem Karimov on 2013-01-19.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSColor (AgileBits)

- (void)drawAsPatternInRect:(NSRect)rect;
+ (NSColor *)ag_appTintColor;
- (NSColor *)ag_lighterColor:(CGFloat)amount;
- (NSColor *)ag_darkerColor:(CGFloat)amount;

@end
