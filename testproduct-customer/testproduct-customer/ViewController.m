//
//  ViewController.m
//  testproduct-customer
//
//  Created by zuoyongyong on 2017/7/31.
//  Copyright © 2017年 zuoyongyong. All rights reserved.
//

#import "ViewController.h"
#include "data.h"
#include <pthread.h>
#include <stdio.h>


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    pthread_t thread_pro;
    pthread_t thread_cons;
    printf("create....\n");
    
    //创建生产者线程。
    pthread_create(&thread_pro,NULL,(void *)producer,NULL);
    
    //创建消费者线程。
    pthread_create(&thread_cons,NULL,(void *)customer,NULL);
    printf("finished!\n");
    while(1){
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
