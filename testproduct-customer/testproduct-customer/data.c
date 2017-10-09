//
//  data.c
//  testproduct-customer
//
//  Created by zuoyongyong on 2017/7/31.
//  Copyright © 2017年 zuoyongyong. All rights reserved.
//

/***********data.c************/

#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct product *present_product=NULL;

struct product *pre_product = NULL;

int lock=0;


void addProduct(char *product_data){
    while(lock==1);
    lock=1;
    struct product *new_product=malloc(sizeof(struct product));
    if(present_product==NULL){
        new_product->pre_product=NULL;
        strcpy( new_product->product_data,product_data);
        new_product->next_product=NULL;
        present_product=new_product;
    }else{
        new_product->pre_product=present_product;
        strcpy( new_product->product_data,product_data);
        new_product->next_product=NULL;
        present_product->next_product=new_product;
        present_product=new_product;
    }
    lock=0;
}


void consProduct(){
    while(lock==1);
    lock=1;
    while(present_product!=NULL){
        pre_product=present_product->pre_product;
        printf("%s\n",present_product->product_data);
        if(pre_product!=NULL){
            pre_product->next_product=0;
        }
        free(present_product);
        present_product=pre_product;
    }
    lock=0;
}

int temp_i=0;
void producer(){
    char temp[20]={0};
    while(1){
        sprintf(temp,"number___%d",temp_i);
        addProduct(temp);
        temp_i++;
        usleep((int)(rand()/2000));
    }
}  

void customer(){
    while(1){
        consProduct();
        printf("-------------\n");
        usleep((int)(rand()/1000));
    }  
}
