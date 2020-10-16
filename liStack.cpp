//
// Created by ManT on 2020/10/11 0011.
//
#include "liStack.h"

// 初始化链表
PLinkStack Init_LinkStack(void){
    /* 初始化链栈，入口参数为空，返回值：链栈指针，null表示初始化失败 */
    PLinkStack S;
    S = (PLinkStack)malloc(sizeof(LinkStack));
    if (S) {
        S->top=NULL;
    }
    return S;
}

// 判断栈是否为空
bool Empty_LinkStack(PLinkStack S){
    if (S->top == NULL) {
        return true;
    }else{
        return false;
    }
}

// 入栈，进栈都是头插法，所以p->next = S->top ,这里top指的是带头节点的
bool Push_LinkStack(PLinkStack S,DataType x) {
    PLinkStack p;
    p=(PLinkStack)malloc(sizeof(LinkStack));
    if (!p){
        printf("内存溢出！");
        return false;
    }
    p->data =x;
    p->next = S->top;
    S->top=p;
    return true;
}

// 出栈
bool Pop_LinkStack(PLinkStack S,DataType *x) {
    PLinkStack p;
    if (Empty_LinkStack(S)) {
        printf("栈空，不能出栈");
        return false;
    }
    *x = S->top->data;
    p=S->top;
    S->top = p->next;
    free(p);
    return true;
}

// 取栈顶元素
int GetTop_LinkStack(PLinkStack S,DataType *x){
    if (Empty_LinkStack(S)) {
        printf("栈空，没有元素");
        return 0;
    } else{
        *x=S->top->data;
        return -1;
    }
}

// 清空栈
void Clear_Stack(PLinkStack S){
    int * value;
    if (!Empty_LinkStack(S)) {
        Pop_LinkStack(S,value);
    }
}

// 销毁栈
void Destroy_LinkStack(PLinkStack S){
    PLinkStack p,q;
    if (S) {
        p=S->top;
        while (p) {
            q=p;
            p=p->next;
        }
    }
}

