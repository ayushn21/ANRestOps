//
//  ANRestOps.h
//  ANRestOps
//
//  Created by Ayush Newatia on 31/12/2014.
//  Copyright (c) 2014 Spectrum. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ANRestOpsClient.h"
#import "ANRestOpsResponse.h"

@interface ANRestOps : NSObject

typedef void(^ANRestOpsBatchCompletionHandler)(NSDictionary *);
typedef NS_ENUM(NSUInteger, ANRestOpsDataFormat)
{
    ANRestOpsJSONFormat,
    ANRestOpsFormFormat
};

+ (ANRestOpsResponse *)get:(NSString *)urlString;
+ (ANRestOpsResponse *)get:(NSString *)urlString withParameters:(NSDictionary *)parameters;


+ (void)getInBackground:(NSString *)urlString
          beforeRequest:(void (^)(void))startingBlock
           onCompletion:(ANRestOpsCompletionHandler)completionBlock;

+ (void)getInBackground:(NSString *)urlString
             parameters:(NSDictionary *)parameters
          beforeRequest:(void (^)(void))startingBlock
           onCompletion:(ANRestOpsCompletionHandler)completionBlock;


+ (ANRestOpsResponse *)post:(NSString *)urlString payload:(NSString *)payload;
+ (ANRestOpsResponse *)post:(NSString *)urlString payload:(NSDictionary *)payload payloadFormat:(ANRestOpsDataFormat)format;

+ (void)postInBackground:(NSString *)urlString
                 payload:(NSString *)payload
           beforeRequest:(void (^)(void))startingBlock
            onCompletion:(ANRestOpsCompletionHandler)completionBlock;

+ (void)postInBackground:(NSString *)urlString
                 payload:(NSDictionary *)payload
           payloadFormat:(ANRestOpsDataFormat)format
           beforeRequest:(void (^)(void))startingBlock
            onCompletion:(ANRestOpsCompletionHandler)completionBlock;

@end
