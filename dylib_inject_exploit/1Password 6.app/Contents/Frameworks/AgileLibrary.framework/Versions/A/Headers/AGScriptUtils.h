//
//  AGScriptUtils.h
//  1PasswordAgent
//
//  Created by Chad Seldomridge on 8/15/11.
//  Copyright 2011 AgileBits, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    NSDictionary* runScriptWaitForExit(NSString *scriptName, NSString *params, NSData* standardInput, BOOL waitForExit);
 	NSDictionary* runScript(NSString *scriptName, NSString *params, NSData* standardInput);
	NSDictionary* runTask(NSString *taskPath, NSArray *params, NSData* standardInput);
    BOOL runShellWithAuthorization(NSString *prompt, NSString *shellCommand);
    
    BOOL rubyExists(void);
	NSString *rubyVersion(void);
    NSString *rubyPath(void);
    NSDictionary *runRubyScript(NSString *scriptName, NSString *params);
    NSDictionary *runRubyScriptWaitForResponse(NSString *scriptName, NSString *params);
    NSDictionary *runRubyScriptWithStandarInput(NSString *scriptName, NSString *params, NSData *standardInput);
    NSDictionary *runRubyScriptWithStandarInputWaitForResponse(NSString *scriptName, NSString *params, NSData *standardInput, BOOL waitForExit);
    
	
#ifdef __cplusplus
}
#endif