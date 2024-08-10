//
//  NSBezierPath+AgileBits.h
//  OnePasswordOSX
//
//  Created by Roustem Karimov on 2013-05-03.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

enum {
	cornerTopLeft = 1 << 0,
	cornerTopRight = 1 << 1,
	cornerBottomRight = 1 << 2,
	cornerBottomLeft = 1 << 3,
	
	cornerAll = 0xFF
};

@interface NSBezierPath (AgileBits)

+ (NSBezierPath *)bezierPathWithRect:(NSRect)rect radius:(CGFloat)radius roundedCorners:(NSInteger)roundedCorners;
- (CGPathRef)ag_quartzPath;

@end
