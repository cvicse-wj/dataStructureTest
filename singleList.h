#ifndef TEST_SINGLELIST_H
#define TEST_SINGLELIST_H

#include "common.h"

typedef struct LNode{
    DataType data;
    struct LNode* next;
}LNode,*LinkList;


bool InitListNoHead(LinkList &l);
bool InitList(LinkList &l);
bool EmptyListNoHead(LinkList &l);
bool EmptyList(LinkList &l);
void ListInsert(LinkList &list,int index,int value);
void ListInsertNoHead(LinkList &list,int index,int value);
// ָ���ڵ������
bool InsertNextNode (LNode *p,int value);
// ָ���ڵ�ǰ�����
bool InsertPriorNode (LNode *p,int value);
// ��λ��ɾ����Ԫ��
bool ListDelete(LinkList &list,int index,int &value);
/**
 *  ɾ��ָ���ڵ㣨��λ˼�룩
 *  ˼�룺�ӵ�ǰԪ�غ�ɾ��һ��Ԫ�أ�Ȼ�󽫵�ǰԪ�����ɾ��Ԫ��ֵ�໥�滻
 * */
bool DeleteNode(LNode *p);
// ��λ���ң����ص�index��Ԫ��
LNode * GetElem(LinkList list,int index);
// ��ֵ����
LNode * LocateElem(LinkList list,int value);
// ��ȡ��������
int Length(LinkList list);
// β�巨
LinkList List_TailInsert(LinkList &list);
void CreatList_tail(LinkList &L, int n);


//���������
void printList(LinkList &L);






#endif
