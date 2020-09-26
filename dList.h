//
// Created by ManT on 2020/9/25 0025.
//

#ifndef TEST_DLIST_H
#define TEST_DLIST_H
#include "common.h"

// 定义双链表
typedef struct DNode{
    DataType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;


#endif //TEST_DLIST_H
