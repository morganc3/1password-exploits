//
//  NSString+SecureString.h
//  ApplicationFrameworks
//
//  Created by Nathan Van Fleet on 2015-07-15.
//
//

#import <Foundation/Foundation.h>

@interface NSString (SecureString)
+ (instancetype)secureStringFromString:(NSString *)string;
+ (instancetype)secureStringFromData:(NSData *)data;
@end

CFMutableStringRef AG_CFStringCreateSecureMutableFromNSString(NSString *string);
