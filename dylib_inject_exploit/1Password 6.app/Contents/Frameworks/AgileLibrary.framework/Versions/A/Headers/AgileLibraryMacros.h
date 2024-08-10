//
//  AgileLibraryMacros.h
//  ApplicationFrameworks
//
//  Created by Roustem Karimov on 2014-08-29.
//
//

#import <Foundation/Foundation.h>

#define DISPATCH_TIME_SECONDS_FROM_NOW(seconds) dispatch_time(DISPATCH_TIME_NOW, (int64_t)((double)(seconds) * NSEC_PER_SEC))
#define DISPATCH_TIME_MINUTES_FROM_NOW(minutes) dispatch_time(DISPATCH_TIME_NOW, (int64_t)((double)(minutes) * 60 * NSEC_PER_SEC))
#define DISPATCH_TIME_HOURS_FROM_NOW(hours) dispatch_time(DISPATCH_TIME_NOW, (int64_t)((double)(hours) * 3600 * NSEC_PER_SEC))

//This macro should be used for things that need to happen regardless of system sleep.
#define DISPATCH_WALLTIME_SECONDS_FROM_NOW(seconds) dispatch_walltime(DISPATCH_TIME_NOW, (int64_t)((double)(seconds) * NSEC_PER_SEC))


//This macro should be used to define an observation context value for a given class in order to ensure that we're working with the right observer, subclassing can negatively impact observer handling when no context is provided
//use example:
// in OPHelperAppDelegate define AG_KVO_CONTEXT(OPHelperAppDelegateObservationContext); in the top of the file around/near the NSString constants
//to make use of the observation context:
// [[NSUserDefaults standardUserDefaults] addObserver:self forKeyPath:OPPrefShowStatusItem options:NSKeyValueObservingOptionNew context:&OPHelperAppDelegateKVOContext];
//to catch the observer correctly:
// in -[observeValueForKeyPath:ofObject:change:context:] check that (context == &OPHelperAppDelegateKVOContext) as a precursor to evaluating the keyPath

typedef void * _AGKVOContext;

#ifndef AG_KVO_CONTEXT
#define AG_KVO_CONTEXT(x) static _AGKVOContext x = (_AGKVOContext)@#x
#endif
