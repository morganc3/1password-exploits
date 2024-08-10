//
//  AGLogger.h
//  OnePasswordiOS
//
//  Created by Roustem Karimov on 12-04-18.
//  Copyright (c) 2012 AgileBits. All rights reserved.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import "AgileLibraryLoggerSettings.h"

typedef enum {
	AGLoggerConsoleFormatShort,
	AGLoggerConsoleFormatLong,
} AGLoggerConsoleFormat;

extern AGLoggerConsoleFormat AGLOGGER_CONSOLE_FORMAT;

#define AGLOG_STRINGIFY1(x) #x
#define AGLOG_STRINGIFY(x) AGLOG_STRINGIFY1(x)

//
// Can be enabled or disabled at run time.
// In DEBUG, log both to SQLite and NSLog
//

#define log_at					do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self at:_cmd format:nil]; }} while(0)
#define log_enter				CFAbsoluteTime aglog_enter_time = CFAbsoluteTimeGetCurrent(); do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self enter:_cmd format:nil]; }} while(0)
#define log_exit				do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self exit:_cmd elapsed:(CFAbsoluteTimeGetCurrent() - aglog_enter_time) format:nil]; }} while(0)
#define log_profile(fmt,...)	do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self profile:_cmd elapsed:(CFAbsoluteTimeGetCurrent() - aglog_enter_time) format:fmt, ##__VA_ARGS__]; }} while(0)

#define log_at_f(fmt,...)		do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self at:_cmd format:fmt, ##__VA_ARGS__]; }} while(0)
#define log_enter_f(fmt,...)	CFAbsoluteTime aglog_enter_time = CFAbsoluteTimeGetCurrent(); do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self enter:_cmd format:fmt, ##__VA_ARGS__]; }} while(0)
#define log_exit_f(fmt,...)		do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) object:self exit:_cmd elapsed:(CFAbsoluteTimeGetCurrent() - aglog_enter_time) format:fmt, ##__VA_ARGS__]; }} while(0)

#define log_info(fmt,...)		do { if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM event:"I" console:NO object:self method:_cmd format:fmt, ##__VA_ARGS__]; }} while(0)


//
// DEBUG only, stripped out in Release mode
//
#if DEBUG
	#define log_debug(fmt,...)	do {  if (AGLOGGER_SUBSYSTEM) { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM event:"D" console:NO object:self method:_cmd format:fmt, ##__VA_ARGS__]; }} while(0)
#else
	#define log_debug(fmt,...)	do { } while(0)
#endif


//
// Always enabled
//
#define log_warn(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM object:self method:_cmd warn:fmt, ##__VA_ARGS__]; } while(0)
#define log_error(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM object:self method:_cmd error:fmt, ##__VA_ARGS__]; } while(0)
#define log_important(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM event:"M" console:YES object:self method:_cmd format:fmt, ##__VA_ARGS__]; } while(0)
#define log_status(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM event:"S" console:NO object:self method:_cmd format:fmt, ##__VA_ARGS__]; } while(0)
#define log_exception(e) do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM object:self method:_cmd file:__FILE__ line:__LINE__ exception:e]; } while(0)
#define log_assert(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM object:self method:_cmd file:__FILE__ line:__LINE__ assertion:fmt, ##__VA_ARGS__]; } while(0)
#define log_assert_f(fmt,...)	do { [[AGLogger sharedLogger] log: AGLOG_STRINGIFY(AGLOGGER_SUBSYSTEM) subsystemEnabled:AGLOGGER_SUBSYSTEM object:nil method:nil file:__FILE__ line:__LINE__ assertion:fmt, ##__VA_ARGS__]; } while(0)

@interface AGLogger : NSObject

+ (NSURL *)logsDirectoryURL;

+ (AGLogger *)sharedLogger;
+ (NSMutableString *)recentLogContentsAtURL:(NSURL *)url limitedToSize:(NSUInteger)maxBytes;
+ (NSMutableString *)recentLogContentsLimitedToSize:(NSUInteger)maxBytes;
+ (NSMutableString *)recentExtensionLogContentsLimitedToSize:(NSUInteger)maxBytes;
+ (NSMutableString *)recentWatchExtensionLogContentsLimitedToSize:(NSUInteger)maxBytes;

@property (nonatomic, strong) NSString * appVersion;
@property (nonatomic, assign) long appBuildNumber;

- (void)open;
- (void)close;

- (void)deleteLogsOlderThan:(unsigned long long)timestamp;
- (void)rotateMacLogs;

- (void)log:(const char *)subsystem object:(id)object at:(SEL)method format:(NSString *)format args:(va_list)args;
- (void)log:(const char *)subsystem object:(id)object at:(SEL)method format:(NSString *)format,... NS_FORMAT_FUNCTION(4,5);
- (void)log:(const char *)subsystem object:(id)object enter:(SEL)method format:(NSString *)format,... NS_FORMAT_FUNCTION(4,5);
- (void)log:(const char *)subsystem object:(id)object exit:(SEL)method elapsed:(CFAbsoluteTime)elapsed format:(NSString *)format,... NS_FORMAT_FUNCTION(5,6);
- (void)log:(const char *)subsystem object:(id)object profile:(SEL)method elapsed:(CFAbsoluteTime)elapsed format:(NSString *)format,... NS_FORMAT_FUNCTION(5,6);

- (void)log:(const char *)subsystem subsystemEnabled:(BOOL)onlyForCompilerWarning event:(const char *)event console:(BOOL)console object:(id)object method:(SEL)method format:(NSString *)format,... NS_FORMAT_FUNCTION(7,8);
- (void)log:(const char *)subsystem subsystemEnabled:(BOOL)onlyForCompilerWarning object:(id)object method:(SEL)method warn:(NSString *)format,... NS_FORMAT_FUNCTION(5,6);
- (void)log:(const char *)subsystem subsystemEnabled:(BOOL)onlyForCompilerWarning object:(id)object method:(SEL)method error:(NSString *)format,... NS_FORMAT_FUNCTION(5,6);

- (void)log:(const char *)subsystem subsystemEnabled:(BOOL)onlyForCompilerWarning object:(id)object method:(SEL)method file:(const char *)file line:(int)line assertion:(NSString *)format,... NS_FORMAT_FUNCTION(7,8);
- (void)log:(const char *)subsystem subsystemEnabled:(BOOL)onlyForCompilerWarning object:(id)object method:(SEL)method file:(const char *)file line:(int)line exception:(NSException *)e;

// For AGLogger.swift
- (void)log:(NSString *)subsystem
	elapsed:(CFAbsoluteTime)elapsed
	  event:(NSString *)event
	console:(BOOL)console
	   file:(NSString *)file
   function:(NSString *)function
	   line:(NSInteger)line
	 column:(NSInteger)column
	message:(NSString *)message;

- (void)log_assert:(NSString *)subsystem
	   file:(NSString *)file
   function:(NSString *)function
	   line:(NSInteger)line
	 column:(NSInteger)column
	message:(NSString *)message;

@end

#else


#define log_at do { } while(0)
#define log_enter do { } while(0)
#define log_exit do { } while(0)
#define log_profile(fmt,...) do { } while(0)
#define log_at_f(fmt,...) do { } while(0)
#define log_enter_f(fmt,...) do { } while(0)
#define log_exit_f(fmt,...)	do { } while(0)
#define log_info(fmt,...) do { } while(0)
#define log_debug(fmt,...)	do { } while(0)
#define log_warn(fmt,...) do { } while(0)
#define log_error(fmt,...) do { } while(0)
#define log_important(fmt,...) do { } while(0)
#define log_exception(e) do { } while(0)
#define log_assert(fmt,...) do { } while(0)
#define log_assert_f(fmt,...) do { } while(0)

#endif
