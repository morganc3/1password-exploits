//
//  NSIndexPath+AgileBits.h
//  OnePasswordOSX
//
//  Created by Dave Teare on 12-04-15.
//  Copyright (c) 2012 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSIndexPath (AgileBits)

+ (NSIndexPath *)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;

@property(nonatomic,readonly) NSInteger section;
@property(nonatomic,readonly) NSInteger row;

@end
