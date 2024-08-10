//
//  NSString+Validation.h
//  ApplicationFrameworks
//
//  Created by Nathan Van Fleet on 2015-08-07.
//
//

#import <Foundation/Foundation.h>

@interface NSString (Validation)

- (BOOL)validateAsEmail;
- (BOOL)validateAsURL;
- (BOOL)validateAsString;

- (NSString *)validStringAsEmail;
- (NSString *)validStringAsURL;
- (NSString *)validString;
@end
