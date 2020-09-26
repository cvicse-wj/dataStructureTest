#include "common.h"

typedef struct {
    DataType *data;
    int length;
    int MaxSize;
}SeqList;

void Init_SeqList(SeqList &pl);
void Increase_Value(SeqList &pl,int value);
void Show_SeqList(SeqList &pl);
void Increase_SeqList(SeqList &pl,int len);
void Insert_SeqList(SeqList &pl ,int i,DataType x);
void Delete_SeqList(SeqList &pl,int i) ;
int getValueByIndex(SeqList &pl,int index);
int getIndexByValue(SeqList &pl,int value) ;
