//
//  NSFileManager+Agile.h
//  OnePasswordOSX
//
//  Created by Chad Seldomridge on 5/24/13.
//  Copyright (c) 2013 AgileBits Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *NSFileManagerAgileErrorDomain;
FOUNDATION_EXPORT NSUInteger NSFileManagerAgileErrocCodeURLNotADirectory;

@interface NSFileManager (Agile)

- (BOOL)ag_lockItemAtURL:(NSURL *)url error:(NSError **)error;
- (BOOL)ag_unlockItemAtURL:(NSURL *)url error:(NSError **)error;
- (BOOL)ag_removeLockedDirectoryAtURL:(NSURL *)url error:(NSError **)error;


- (BOOL)ag_currentUserOwnsPath:(NSString *)oPath;

- (BOOL)ag_movePathWithAuthentication:(NSString *)src toPath:(NSString *)dst;
- (BOOL)ag_copyPathWithAuthentication:(NSString *)src toPath:(NSString*)dst;
- (BOOL)ag_copyPathWithRootAdminPermissions:(NSString *)src toPath:(NSString*)dst;
- (BOOL)ag_trashPathWithAuthentication:(NSString *)path;
- (BOOL)ag_deletePathWithAuthentication:(NSString *)path;

@end
