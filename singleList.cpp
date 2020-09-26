#include "singleList.h"

// 初始化单链表
bool InitListNoHead(LinkList &l) {
    // 这里置为NULL，防止脏数据，注意用NULL大写的
    l = NULL;
    return true;
}

bool InitList(LinkList &l) {
    // 这里置为NULL，防止脏数据，注意用NULL大写的
    l = (LinkList)malloc(sizeof(LNode));
    if (l ==NULL) {
        return false;
    } else{
        // 如果有头结点，需要将其置为NULL
        l->next =NULL;
        return true;
    }
}

// 判断单链表是否为空
bool EmptyListNoHead(LinkList &l) {
    if(l == NULL) {
        return true;
    }else{
        return false;
    }
}

bool EmptyList(LinkList &l) {
    // 带头节点的单链表
    if(l->next == NULL) {
        return true;
    }else{
        return false;
    }
}

// 按位序插入
void ListInsert(LinkList &list,int index,int value) {
    if (index<1) {
        printf("插入非法位置\n");
    }
    // 定义指针，意思是从头开始扫描，找到当前扫描的节点
    LNode * cp;
    /**
     * 当前cp指向第几个节点,带头节点，默认指向头结点，
     * 该头节点可以认为位序是0，所以j=0；但是不带头节点，则从1开始
     * */
    int j = 0;
    // list 指向头节点，头节点是第0个节点
    cp = list;
    /**
     * 注意这个while循环之后返回的index-1的前驱节点，并不是index-1这个节点,
     * 这里要判断当前节点是否为NULL，为的是防止超出长度
     * */
    while (cp!= NULL && j<index-1) {
        cp = cp->next;
        j++;
    }
    if (cp == NULL) {
        printf("插入非法位置\n");
    }
    // 新创建指针
    LNode * p =(LNode *)malloc(sizeof(LNode));
    // 进行赋值
    p->data = value;
    // 将原有index-2指向的，赋值给p进行指向
    p->next = cp->next;
    // 将新加入的节点加入
    cp->next = p;
}

void ListInsertNoHead(LinkList &list,int index,int value) {
    if (index<1) {
        printf("插入非法位置\n");
    }
    /**
     * 不带头节点，插入第一个元素跟其他不一样
     * */
    if(index == 1) {
        LNode * s =(LNode *) malloc(sizeof(LNode));
        if(s == NULL) {
            // 内存分配失败（内存不足情况）
            printf("内存分配失败！\n");
        } else {
            s->data = value;
            s->next = list;
            // 头指针指向新节点
            list = s;
            printf("插入成功！\n");
        }
    }else {
        // 定义指针，意思是从头开始扫描，找到当前扫描的节点
        LNode * cp;
        // 当前cp指向第几个节点,不带头节点，默认指向头结点，该头节点可以认为位序是1
        int j = 1;
        // list 指向头节点，头节点是第0个节点
        cp = list;
        /**
         * 注意这个while循环之后返回的index-1的前驱节点，并不是index-1这个节点,
         * 这里要判断当前节点是否为NULL，为的是防止超出长度
         * */
        while (cp!= NULL && j<index-1) {
            cp = cp->next;
            j++;
        }
        if (cp == NULL) {
            printf("插入非法位置\n");
        }
        // 新创建指针
        LNode * p =(LNode *)malloc(sizeof(LNode));
        // 进行赋值
        p->data = value;
        // 将原有index-2指向的，赋值给p进行指向
        p->next = cp->next;
        // 将新加入的节点加入
        cp->next = p;
        printf("插入成功！\n");
    }
}

// 指定节点后插操作
bool InsertNextNode (LNode *p,int value) {
    if (p == NULL) {
        return false;
    }
    LNode *s =(LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存分配失败！\n");
        return false;
    }
    // 保存数据
    s->data =value;
    // s指向拍的下个节点
    s->next=p->next;
    // 将节点s连接p节点
    p->next =s;
    return true;
}

/**
 *  指定节点后插操作（换位思想）
 *  思想：从当前元素后插入一个元素，然后将当前元素与插入元素值相互替换
 * */
bool InsertPriorNode (LNode *p,int value) {
    if (p == NULL) {
        return false;
    }
    LNode *s =(LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存分配失败！\n");
        return false;
    }
    // 保存数据,将p的元素赋值给s
    s->data =p->data;
    // s指向拍的下个节点
    s->next=p->next;
    // 将节点s连接p节点
    p->next =s;
    // 将p的值进行修改，完成置换操作
    p->data=value;
    return true;
}

// 按位序删除的元素
bool ListDelete(LinkList &list,int index,int &value) {
    if (index < 1){
        return false;
    }
    LNode *p;
    int j=0;
    // list指向头节点，头节点是第0个节点（不存在数据）
    p=list;
    while (p!=NULL && j<index-1) {
        p=p->next;
        j++;
    }
    // 当前p节点是index-1位置的节点，若它为NULL，说明它是末尾节点，则说明删除的元素不存在
    if (p == NULL) {
        printf("非法位置\n");
        return false;
    }
    LNode * s = p->next;
    // 返回被删除元素的值
    value = s->data;
    p->next =s->next;
    // 注意要释放节点
    free(p);
    return true;
}

/**
 *  删除指定节点（换位思想）
 *  思想：从当前元素后删除一个元素，然后将当前元素与后删除元素值相互替换
 * */
bool DeleteNode(LNode *p) {
    if (p == NULL)  {
        // 说明p是最后节点的后节点
        printf("非法位置\n");
        return false;
    }
    // 获取p的后继节点
    LNode *q = p->next;
    // 这里注意考虑最后一个元素的这个情况，如果是的话，则会报空指针，这种情况只能从头遍历
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找，返回第index个元素
LNode * GetElem(LinkList list,int index) {
    if (index <0) {
        return NULL;
    }
    // 定义指针p，指向list的头结点
    LNode * p = list;
    int j=0;
    // 循环到第几个节点
    while (p!=NULL && j<index) {
        p=p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode * LocateElem(LinkList list,int value) {
    LNode *p =list->next;
    while (p!=NULL && p->data != value) {
        p=p->next;
    }
    return p;
}

// 获取单链表长度
int Length(LinkList list) {
    LNode * p = list;
    int length=0;
    // 注意这里是判断后继节点是否是Null
    while (p->next!=NULL) {
        p=p->next;
        length++;
    }
    return length;
}

// 尾插法
LinkList List_TailInsert(LinkList &list) {
    int x;
    // 初始化，建立头节点
    list = (LinkList)malloc(sizeof(LNode));
    // 指向NUll
//    list->next=NULL;
    /**
     * 定义2个指针
     * r指向list
     * */
    LNode *s,*r =list;
    printf("请输入：");
    scanf("%d",&x);
    while (x!=999) {
        // 在r节点之前插入元素x
        s = (LNode*)malloc(sizeof(LNode));
        if (s == NULL) {
            printf("失败！");
        }
        s->data =x;
        r->next=s;
        // r指向新的表尾节点，永远保证r指向最后一个元素
        r=s;
        printf("请输入：");
        scanf("%d",&x);
    }
    // 尾节点指针置空
    r->next = NULL;
    return list;
}

void CreatList_tail(LinkList &L, int n){
    LinkList p,r;
    r = L;
    int a;
    printf("请输入:\n");
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&a);
        p->data = a;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

// 头插法
void CreatList_head(LinkList &L, int n){
    LinkList p;
    int a;
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&a);
        p->data = a;
        p->next = L->next;
        L->next = p;
    }
 }

 // 头插法
 bool Insert_LinkList(LinkList &list,int value) {
    if (list==NULL) {
        return false;
    }
    LNode *s,*p=list;
    s =(LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    } else{
        s->data =value;
        s->next = p->next;
        p->next =s;
        return true;
    }
}

 LinkList List_Head_Insert(LinkList &list) {
    // 初始化list
    list =(LNode*) malloc(sizeof(LNode));
    list->next=NULL;
    // 定义指针s，和输入变量x
    LNode * s;
    int x;
    printf("请输入：");
    scanf("%d",&x);
    while (x!=999) {
        s =(LNode*) malloc(sizeof(LNode));
        s->data=x;
        s->next=list->next;
        list->next=s;
        printf("请输入：");
        scanf("%d",&x);
    }
     return list;
}

//输出单链表
void printList(LinkList &L){
    LinkList q;
    q = L->next;
    while(q){
        printf("%d ",q->data);
        q = q->next;
    }
}

// 获取A和B的交集
void Inter_src(LinkList A,LinkList B) {
    if (A == NULL || B == NULL) {
        printf("AnB为空！");
    }
    LNode *pre,*p;
    // p节点表示当前节点
    pre=A;
    // q节点表示下一个节点
    p = pre->next;
    while (p) {
        // 这里可以采用按值查找的方法,存在的话，返回该节点，不存在的话，返回的额是NULL，则将该节点删除
        if (LocateElem(B,p->data)) {
            printf("AnB:%d",p->data);
            pre = p;
            p=p->next;
        }else{
            pre->next=p->next;
            free(p);
            p =pre->next;
        }
    }
}

// 获取A和B的并集
void Merge_sec(LinkList A,LinkList B) {
    if (A == NULL || B == NULL) {
        printf("AnB为空！");
    }
    LNode *p;
    // p节点指向第一个节点
    p=B->next;
    while (p) {
        // 这里可以采用按值查找的方法,存在的话，返回该节点，不存在的话，返回的额是NULL，如果不存在采用头插法将其加入A集合中
        if (!LocateElem(B,p->data)) {
            if(Insert_LinkList(A,p->data)){
                p =p->next;
            }
        }
    }
}