//
//  CompareStringSingleton.h
//  ReportServiceCore
//
//  Created by Lin, Weiwei on 4/24/17.
//  Copyright © 2017 MicroStrategy, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#ifndef CompareStringSingleton_h
#define CompareStringSingleton_h

@interface CompareStringSingleton : NSObject
@property(nullable, nonatomic) NSString *LocaleStr;
@property(nullable, nonatomic) NSLocale *Locale;
+ (nullable CompareStringSingleton *)sharedInstance;

- (int)CompareStringWithLocale:(nullable NSString *)str1 withString:(nullable NSString *)str2 options: (NSStringCompareOptions)mask;
@end

#endif /* CompareStringSingleton_h */
