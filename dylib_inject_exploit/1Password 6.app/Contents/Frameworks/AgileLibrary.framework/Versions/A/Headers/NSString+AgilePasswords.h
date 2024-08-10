//
//  NSString+Agile.h
//  1Password
//
//  Created by Chad Seldomridge on 08/11/07.
//  Copyright 2008 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (AgilePasswords)

#if (TARGET_OS_MAC || UNIT_TESTS) && !TARGET_IPHONE_SIMULATOR && !TARGET_OS_IPHONE
- (int)ag_passwordStrength;
- (NSString *)ag_passwordStrengthDescription;
#endif

@end

