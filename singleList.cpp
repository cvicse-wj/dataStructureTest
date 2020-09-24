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

// 删除指定位置的元素
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