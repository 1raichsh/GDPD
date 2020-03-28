//
//  ImageCacheCallback.h
//  MSTRMobile
//
//  Created by Firat Alpergin on 2/23/10.
//  Copyright 2010 MicroStrategy. All rights reserved.
//

/** 	
 *	Protocol renamed from GridWidgetImageCacheCallback to ImageCacheCallback
 */

@protocol ImageCacheCallback <NSObject>

-(void)imageReceived:(UIImage *)image forURL:(NSString*)url withLocalURL:(NSString*)localUrl isHitCache:(BOOL)hitCache;
-(NSString *)getSubscriptionId;

@optional
-(void)imageDataReceived:(NSData *)imageData forURL:(NSString*)url withLocalURL:(NSString*)localUrl isHitCache:(BOOL)hitCache;

@end
