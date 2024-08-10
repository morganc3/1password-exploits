//
//  NSData+SecureData.h
//  ApplicationFrameworks
//
//  Created by Kevin Hayes on 2015-10-20.
//
//

#import <Foundation/Foundation.h>

@interface NSData (SecureData)

+ (instancetype)secureDataFromData:(NSData *)backingData;

@end
