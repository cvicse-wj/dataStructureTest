#include "head.h"

//创建一顺序表
void Init_SeqList(SeqList &pl) {
    // 动态申请一片动态的空间
    pl.data=(int *)malloc(sizeof(int)*InitSize);
    pl.length=0;
    pl.MaxSize = InitSize;
}

// 往列表中添加值
void Increase_Value(SeqList &pl,int value) {
    if(pl.length == InitSize) {
        printf("不能再添加了，已经满了！\n");
    }else{
        pl.data[pl.length] = value;
        pl.length++;
    }
}

// 动态增加数组长度
void Increase_SeqList(SeqList &pl,int len) {
    int *p=pl.data;
    pl.data = (int *)malloc(sizeof(int)*(InitSize+len));
    for (int i = 0; i < pl.length; ++i) {
        pl.data[i] = p[i];
    }
    pl.MaxSize = pl.length+len;
    // 释放空间
    free(p);
}

// 展示顺序表
void Show_SeqList(SeqList &pl) {
    for (int i = 0; i < pl.length; ++i) {
        printf("%d\t",pl.data[i]);
    }
    printf("\n");
}

// 顺序表的插入
void Insert_SeqList(SeqList &pl ,int i,DataType x) {
    if(pl.length >=MAXSIZE) {
        printf("表空间不足");
    }
    if(i<0 || i>pl.length) {
        printf("插入的位置不合法");
    }
    for (int k = pl.length; k > i-1; k--) {
        pl.data[k] = pl.data[k-1];
    }
    pl.data[i-1] = x;
    pl.length++;
}

// 顺序表的删除
void Delete_SeqList(SeqList &pl,int i) {
    if (i<0 || i>pl.length) {
        printf("输入删除的元素有误！\n");
    }
    for (int j = i; j < pl.length; j++) {
        pl.data[j-1] = pl.data[j];
    }
    // 这里将最后一位置为0；
    pl.data[pl.length-1]=0;
    pl.length--;
}

// 顺序表按位查找
int getValueByIndex(SeqList &pl,int index) {
    if(index<0 || index>pl.length-1) {
        return -1;
    }else{
        return pl.data[index-1];
    }
}

// 顺序表按值查找
int getIndexByValue(SeqList &pl,int value) {
    for (int i = 0; i < pl.length; ++i) {
        if (pl.data[i] == value) {
            return ++i;
        }
    }
}

// 约瑟夫问题
int josephus_SeqList(SeqList &josephus_seq,int s,int m) {
    /* 求解约瑟夫问题的出列元素序列入口参数：已经存放数据的顺序把，起始序号s，计数值m */
    /* 出口参数：1表示后成功，0表示表中没有元素 */
    int s1,i,w;
    if (!josephus_seq.length) {
        printf("表中没有元素！");
        return 0;
    }
    /* data数组中下标是从0开始 */
    s1 =s-1;
    printf("输出约瑟夫序列：");
    for (i = josephus_seq.length; i>0 ; i--) {
        /* 找到出列元素的下标 */
        s1=(s1+m-1)%i;
        w = josephus_seq.data[s1];
        printf("%d\t",w);
        /* 调用方法，删除出列元素 */
        Delete_SeqList(josephus_seq,s1+1);
    }
    return 1;
}