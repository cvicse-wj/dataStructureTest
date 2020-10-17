/**
 * Created by ManT on 2020/10/11
 * 链栈
 * 一般采用不带头结点
 * */

#ifndef TEST_LISTACK_H
#include "common.h"
#define TEST_LISTACK_H

typedef struct LinkStack{
    // 数据域
    DataType data;
    LinkStack *next;
    // 定义栈顶
    LinkStack *top;
}LinkStack,*PLinkStack;

// 初始化链表
PLinkStack Init_LinkStack(void);

// 判断栈是否为空
bool Empty_LinkStack(PLinkStack S);

// 入栈
bool Push_LinkStack(PLinkStack S,DataType x);

// 出栈
int Pop_LinkStack(PLinkStack S);

// 取栈顶元素
int GetTop_LinkStack(PLinkStack S);

// 清空栈
void Clear_Stack(PLinkStack S);

// 销毁栈
void Destroy_LinkStack(PLinkStack S);

#endif
