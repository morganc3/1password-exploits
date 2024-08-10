//
//  NSData+ZLib.h
//  AgileLibrary
//
//  Created by Roustem Karimov on 03/07/08.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSData (ZLib) 

- (NSData *)ag_gzipInflate;
- (NSData *)ag_gzipDeflate;
- (unsigned long)ag_crc32;
- (NSString *)ag_crc32hex;

@end
