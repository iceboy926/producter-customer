//
//  data.h
//  testproduct-customer
//
//  Created by zuoyongyong on 2017/7/31.
//  Copyright © 2017年 zuoyongyong. All rights reserved.
//

#ifndef data_h
#define data_h


/************data.h***********/



//单向链表数据结构
struct product{
    struct product *pre_product;
    char product_data[20];
    struct product *next_product;
};

//向单向链表中加入一个节点（生产）。
void addProduct(char *product_data);

//从单向链表中取出全部节点信息（消费）。
void consProduct();

void producer(); 

void customer(); 

#endif /* data_h */
