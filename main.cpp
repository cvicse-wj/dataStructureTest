//#include "head.h"
#include "singleList.h"
#include "liStack.h"

// 不用if,while循环算累加信息
int Sum_Solution(int n) {
    n>1 && (n+=Sum_Solution(n-1));
    return n;
}

int main() {
    PLinkStack S;
    S=Init_LinkStack();
    int value;
    int *v;
    int n=100;
    int r=8;
    while (n) {
        printf("%d\n",n%r);
        Push_LinkStack(S,n%r);
        n/=r;
    }
    printf("出栈开始---\n");
    while (!Empty_LinkStack(S)) {
       if(Pop_LinkStack(S)!=-1);
    }
    printf("出栈结束---\n");
    return 0;
};



void test() {
//    SeqList pl;
//    Init_SeqList(pl);
//    for (int i = 0; i < 6; ++i) {
//        Increase_Value(pl,i);
//    }
//    printf("%d\n",pl.length);
//    Insert_SeqList(pl,4,0);
//    Show_SeqList(pl);
//    Delete_SeqList(pl,2);
//    Show_SeqList(pl);
//    printf("%d\n",getValueByIndex(pl,2));
//    printf("%d\n",getIndexByValue(pl,4));

//    LinkList L;
//    if (InitList(L)) {
//        printf("请选择：\n1、头插法创建单链表\n2、尾插法创建单链表\n\n请你选择创建方式：");
//        int x;
//        scanf("%d",&x);
//        if(x==1){
//            printf("头插法创建单链表：\n\n请你输入创建数据元素的个数：");
//            int n;
//            scanf("%d",&n);
//            //CreatList_head(L,n);//头插法创建单链表
//            //printList(L);//输出
//        }
//        if(x==2){
//            printf("您选择的是尾插法创建单链表：\n\n请你输入创建数据元素的个数：");
//            int n;
//            scanf("%d",&n);
//            CreatList_tail(L,n);//头插法创建单链表
//            printList(L);//输出
//        }
//    }
}