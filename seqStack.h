/**
 * Created by ManT on 2020/10/11
 * 顺序栈
 * */

#ifndef TEST_SEQSTACK_H
#define TEST_SEQSTACK_H
#include "common.h"

// 定义顺序栈
typedef struct {
    // 静态数组存放栈中元素
    DataType data[MAXSIZE];
    // 设置栈顶指针
    int top;
}SeqStack, * PSeqStack;

// 定义共享栈
typedef struct {
    DataType data[MAXSIZE];
    // 0号栈栈顶指针
    int top0;
    // 1号栈栈顶指针
    int top1;
}ShStack;

// 初始化共享栈
void Init_ShStack(ShStack &shStack);

// 判断共享栈是否已满
bool Full_ShStack(ShStack &shStack);

// 初始化顺序栈
void Init_Stack(SeqStack &stack);

// 判断是否空栈
bool Empty_Stack(SeqStack &stack);

// 入栈
bool Push_Stack(SeqStack &stack,DataType &x);

// 出栈
bool Pop_Stack(SeqStack &stack,DataType &x);

// 取栈顶元素
bool GetTop_Stack(SeqStack &stack,DataType &x);

#endif
