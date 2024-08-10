//
//  NSData+AWS.h
//  1Password
//
//  Created by Roustem Karimov on 9/1/07.
//  Copyright 2007 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Agile)

- (NSString *)ag_asString;
- (NSString *)ag_base32lcEncode; // Base32 in lowercase

@end
