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
// 指定节点后插操作
bool InsertNextNode (LNode *p,int value);
// 指定节点前插操作
bool InsertPriorNode (LNode *p,int value);
// 按位序删除的元素
bool ListDelete(LinkList &list,int index,int &value);
/**
 *  删除指定节点（换位思想）
 *  思想：从当前元素后删除一个元素，然后将当前元素与后删除元素值相互替换
 * */
bool DeleteNode(LNode *p);
// 按位查找，返回第index个元素
LNode * GetElem(LinkList list,int index);
// 按值查找
LNode * LocateElem(LinkList list,int value);
// 获取单链表长度
int Length(LinkList list);
// 尾插法
LinkList List_TailInsert(LinkList &list);
void CreatList_tail(LinkList &L, int n);


//输出单链表
void printList(LinkList &L);






#endif
