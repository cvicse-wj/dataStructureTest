/**
 * Created by ManT on 2020/10/11
 * 链栈
 * */

#ifndef TEST_LISTACK_H
#include "common.h"
#define TEST_LISTACK_H
typedef struct LinkNode{
    // 数据域
    DataType data;
    // 指针域
    struct LinkNode *next;
} *LiStack;


#endif
