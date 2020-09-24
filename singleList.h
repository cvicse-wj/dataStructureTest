#ifndef TEST_SINGLELIST_H
#define TEST_SINGLELIST_H

#define DataType int
#define InitSize 10 //Ĭ����󳤶�
#define MAXSIZE 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
#endif
