//
//  ImageRequestImpl.h
//  MSTRMobile
//
//  Created by Firat Alpergin on 2/23/10.
//  Copyright 2010 MicroStrategy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MSICommonURLRequest.h"

@class MSIProjectInfo;

@interface ImageRequestImpl : MSICommonURLRequest {
	NSString *imageURL;
	MSIProjectInfo *projectInfo;  
}

@property (nonatomic, copy) NSString *imageURL;
@property (nonatomic, strong) MSIProjectInfo *projectInfo;

+ (NSString *)getImageBaseUrlFromProjectInfo:(MSIProjectInfo *) projectInfo;


@end
