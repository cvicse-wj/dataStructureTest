//#include "head.h"
#include "singleList.h"
#include "liStack.h"

// ����if,whileѭ�����ۼ���Ϣ
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
    printf("��ջ��ʼ---\n");
    while (!Empty_LinkStack(S)) {
       if(Pop_LinkStack(S)!=-1);
    }
    printf("��ջ����---\n");
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
//        printf("��ѡ��\n1��ͷ�巨����������\n2��β�巨����������\n\n����ѡ�񴴽���ʽ��");
//        int x;
//        scanf("%d",&x);
//        if(x==1){
//            printf("ͷ�巨����������\n\n�������봴������Ԫ�صĸ�����");
//            int n;
//            scanf("%d",&n);
//            //CreatList_head(L,n);//ͷ�巨����������
//            //printList(L);//���
//        }
//        if(x==2){
//            printf("��ѡ�����β�巨����������\n\n�������봴������Ԫ�صĸ�����");
//            int n;
//            scanf("%d",&n);
//            CreatList_tail(L,n);//ͷ�巨����������
//            printList(L);//���
//        }
//    }
}