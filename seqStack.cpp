/**
 * Created by ManT on 2020/10/11
 * 顺序栈
 * */

#include "seqStack.h"

/**
 * 初始化共享栈
 * 共享栈：是从2头向中间增加的
 * 所以定义2个栈顶指针，上面的栈顶指针初始化为栈的最大容量，下面的栈顶元素设置为-1
 * */
void Init_ShStack(ShStack &shStack){
    shStack.top0 =-1;
    shStack.top1 =MAXSIZE;
}

/**
 * 判断共享栈是否已满
 * 共享栈满的条件：top0+1= top1;
 * */
bool Full_ShStack(ShStack &shStack){
    if (shStack.top0+1 == shStack.top1) {
        return true;
    } else{
        return false;
    }
}

// 初始化顺序栈
void Init_Stack(SeqStack &stack) {
    // 初始化栈顶指针
    stack.top = -1;
}

// 判断是否空栈
bool Empty_Stack(SeqStack &stack){
    if (stack.top == -1) {
        return true;
    } else{
        return false;
    }
}

// 入栈
bool Push_Stack(SeqStack &stack,DataType &x){
    // 首先判断是否栈是否满
    if (stack.top+1 == MAXSIZE) {
        return false;
    } else{
        // 首先将指针加1，再将新元素入栈
        /**
          * stack.top++;
          * stack.data[stack.top] =x;
          * 这2步等价于下面的这样的操作
          * stack.data[++stack.top] =x;
          * 注意这里是stack.data[++stack.top];而不是stack.data[stack.top++]
          * 先后顺序不一样
          * */
        stack.data[++stack.top] =x;
        return true;
    }
}

// 出栈
bool Pop_Stack(SeqStack &stack,DataType &x){
    // 判断栈中是否为空
    if (stack.top == -1) {
        return false;
    } else{
        /**
         * x=stack.data[stack.top];
         * stack.top--;
         * 这2步等价于下面的这样的操作
         * x=stack.data[stack.top--];
         * 注意这里是stack.data[stack.top--];而不是stack.data[--stack.top]
         * */
        x=stack.data[stack.top--];
        return true;
    }
}

// 取栈顶元素
bool GetTop_Stack(SeqStack &stack,DataType &x){
    // 判断栈是否空
    if (stack.top == -1) {
        return false;
    } else{
        x=stack.data[stack.top];
        return true;
    }
}