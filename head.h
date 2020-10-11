/**
 * Created by ManT on 2020/9/11
 * 顺序表
 * */

#include "common.h"

typedef struct {
    DataType *data;
    int length;
    int MaxSize;
}SeqList;

// 创建一顺序表
void Init_SeqList(SeqList &pl);
// 往列表中添加值
void Increase_Value(SeqList &pl,int value);
// 动态增加数组长度
void Increase_SeqList(SeqList &pl,int len);
// 展示顺序表
void Show_SeqList(SeqList &pl);
// 顺序表的插入
void Insert_SeqList(SeqList &pl ,int i,DataType x);
// 顺序表的删除
void Delete_SeqList(SeqList &pl,int i);
// 顺序表按位查找
int getValueByIndex(SeqList &pl,int index);
// 顺序表按值查找
int getIndexByValue(SeqList &pl,int value) ;
// 约瑟夫问题
int josephus_SeqList(SeqList &josephus_seq,int s,int m);
