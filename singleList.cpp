#include "singleList.h"

// ��ʼ��������
bool InitListNoHead(LinkList &l) {
    // ������ΪNULL����ֹ�����ݣ�ע����NULL��д��
    l = NULL;
    return true;
}

bool InitList(LinkList &l) {
    // ������ΪNULL����ֹ�����ݣ�ע����NULL��д��
    l = (LinkList)malloc(sizeof(LNode));
    if (l ==NULL) {
        return false;
    } else{
        // �����ͷ��㣬��Ҫ������ΪNULL
        l->next =NULL;
        return true;
    }
}

// �жϵ������Ƿ�Ϊ��
bool EmptyListNoHead(LinkList &l) {
    if(l == NULL) {
        return true;
    }else{
        return false;
    }
}

bool EmptyList(LinkList &l) {
    // ��ͷ�ڵ�ĵ�����
    if(l->next == NULL) {
        return true;
    }else{
        return false;
    }
}

// ��λ�����
void ListInsert(LinkList &list,int index,int value) {
    if (index<1) {
        printf("����Ƿ�λ��\n");
    }
    // ����ָ�룬��˼�Ǵ�ͷ��ʼɨ�裬�ҵ���ǰɨ��Ľڵ�
    LNode * cp;
    /**
     * ��ǰcpָ��ڼ����ڵ�,��ͷ�ڵ㣬Ĭ��ָ��ͷ��㣬
     * ��ͷ�ڵ������Ϊλ����0������j=0�����ǲ���ͷ�ڵ㣬���1��ʼ
     * */
    int j = 0;
    // list ָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ�
    cp = list;
    /**
     * ע�����whileѭ��֮�󷵻ص�index-1��ǰ���ڵ㣬������index-1����ڵ�,
     * ����Ҫ�жϵ�ǰ�ڵ��Ƿ�ΪNULL��Ϊ���Ƿ�ֹ��������
     * */
    while (cp!= NULL && j<index-1) {
        cp = cp->next;
        j++;
    }
    if (cp == NULL) {
        printf("����Ƿ�λ��\n");
    }
    // �´���ָ��
    LNode * p =(LNode *)malloc(sizeof(LNode));
    // ���и�ֵ
    p->data = value;
    // ��ԭ��index-2ָ��ģ���ֵ��p����ָ��
    p->next = cp->next;
    // ���¼���Ľڵ����
    cp->next = p;
}

void ListInsertNoHead(LinkList &list,int index,int value) {
    if (index<1) {
        printf("����Ƿ�λ��\n");
    }
    /**
     * ����ͷ�ڵ㣬�����һ��Ԫ�ظ�������һ��
     * */
    if(index == 1) {
        LNode * s =(LNode *) malloc(sizeof(LNode));
        if(s == NULL) {
            // �ڴ����ʧ�ܣ��ڴ治�������
            printf("�ڴ����ʧ�ܣ�\n");
        } else {
            s->data = value;
            s->next = list;
            // ͷָ��ָ���½ڵ�
            list = s;
            printf("����ɹ���\n");
        }
    }else {
        // ����ָ�룬��˼�Ǵ�ͷ��ʼɨ�裬�ҵ���ǰɨ��Ľڵ�
        LNode * cp;
        // ��ǰcpָ��ڼ����ڵ�,����ͷ�ڵ㣬Ĭ��ָ��ͷ��㣬��ͷ�ڵ������Ϊλ����1
        int j = 1;
        // list ָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ�
        cp = list;
        /**
         * ע�����whileѭ��֮�󷵻ص�index-1��ǰ���ڵ㣬������index-1����ڵ�,
         * ����Ҫ�жϵ�ǰ�ڵ��Ƿ�ΪNULL��Ϊ���Ƿ�ֹ��������
         * */
        while (cp!= NULL && j<index-1) {
            cp = cp->next;
            j++;
        }
        if (cp == NULL) {
            printf("����Ƿ�λ��\n");
        }
        // �´���ָ��
        LNode * p =(LNode *)malloc(sizeof(LNode));
        // ���и�ֵ
        p->data = value;
        // ��ԭ��index-2ָ��ģ���ֵ��p����ָ��
        p->next = cp->next;
        // ���¼���Ľڵ����
        cp->next = p;
        printf("����ɹ���\n");
    }
}

// ָ���ڵ������
bool InsertNextNode (LNode *p,int value) {
    if (p == NULL) {
        return false;
    }
    LNode *s =(LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return false;
    }
    // ��������
    s->data =value;
    // sָ���ĵ��¸��ڵ�
    s->next=p->next;
    // ���ڵ�s����p�ڵ�
    p->next =s;
    return true;
}

/**
 *  ָ���ڵ����������λ˼�룩
 *  ˼�룺�ӵ�ǰԪ�غ����һ��Ԫ�أ�Ȼ�󽫵�ǰԪ�������Ԫ��ֵ�໥�滻
 * */
bool InsertPriorNode (LNode *p,int value) {
    if (p == NULL) {
        return false;
    }
    LNode *s =(LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return false;
    }
    // ��������,��p��Ԫ�ظ�ֵ��s
    s->data =p->data;
    // sָ���ĵ��¸��ڵ�
    s->next=p->next;
    // ���ڵ�s����p�ڵ�
    p->next =s;
    // ��p��ֵ�����޸ģ�����û�����
    p->data=value;
    return true;
}

// ��λ��ɾ����Ԫ��
bool ListDelete(LinkList &list,int index,int &value) {
    if (index < 1){
        return false;
    }
    LNode *p;
    int j=0;
    // listָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ㣨���������ݣ�
    p=list;
    while (p!=NULL && j<index-1) {
        p=p->next;
        j++;
    }
    // ��ǰp�ڵ���index-1λ�õĽڵ㣬����ΪNULL��˵������ĩβ�ڵ㣬��˵��ɾ����Ԫ�ز�����
    if (p == NULL) {
        printf("�Ƿ�λ��\n");
        return false;
    }
    LNode * s = p->next;
    // ���ر�ɾ��Ԫ�ص�ֵ
    value = s->data;
    p->next =s->next;
    // ע��Ҫ�ͷŽڵ�
    free(p);
    return true;
}

/**
 *  ɾ��ָ���ڵ㣨��λ˼�룩
 *  ˼�룺�ӵ�ǰԪ�غ�ɾ��һ��Ԫ�أ�Ȼ�󽫵�ǰԪ�����ɾ��Ԫ��ֵ�໥�滻
 * */
bool DeleteNode(LNode *p) {
    if (p == NULL)  {
        // ˵��p�����ڵ�ĺ�ڵ�
        printf("�Ƿ�λ��\n");
        return false;
    }
    // ��ȡp�ĺ�̽ڵ�
    LNode *q = p->next;
    // ����ע�⿼�����һ��Ԫ�ص�������������ǵĻ�����ᱨ��ָ�룬�������ֻ�ܴ�ͷ����
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// ��λ���ң����ص�index��Ԫ��
LNode * GetElem(LinkList list,int index) {
    if (index <0) {
        return NULL;
    }
    // ����ָ��p��ָ��list��ͷ���
    LNode * p = list;
    int j=0;
    // ѭ�����ڼ����ڵ�
    while (p!=NULL && j<index) {
        p=p->next;
        j++;
    }
    return p;
}

// ��ֵ����
LNode * LocateElem(LinkList list,int value) {
    LNode *p =list->next;
    while (p!=NULL && p->data != value) {
        p=p->next;
    }
    return p;
}

// ��ȡ��������
int Length(LinkList list) {
    LNode * p = list;
    int length=0;
    // ע���������жϺ�̽ڵ��Ƿ���Null
    while (p->next!=NULL) {
        p=p->next;
        length++;
    }
    return length;
}

// β�巨
LinkList List_TailInsert(LinkList &list) {
    int x;
    // ��ʼ��������ͷ�ڵ�
    list = (LinkList)malloc(sizeof(LNode));
    // ָ��NUll
//    list->next=NULL;
    /**
     * ����2��ָ��
     * rָ��list
     * */
    LNode *s,*r =list;
    printf("�����룺");
    scanf("%d",&x);
    while (x!=999) {
        // ��r�ڵ�֮ǰ����Ԫ��x
        s = (LNode*)malloc(sizeof(LNode));
        if (s == NULL) {
            printf("ʧ�ܣ�");
        }
        s->data =x;
        r->next=s;
        // rָ���µı�β�ڵ㣬��Զ��֤rָ�����һ��Ԫ��
        r=s;
        printf("�����룺");
        scanf("%d",&x);
    }
    // β�ڵ�ָ���ÿ�
    r->next = NULL;
    return list;
}

void CreatList_tail(LinkList &L, int n){
    LinkList p,r;
    r = L;
    int a;
    printf("������:\n");
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&a);
        p->data = a;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

// ͷ�巨
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

 // ͷ�巨
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
    // ��ʼ��list
    list =(LNode*) malloc(sizeof(LNode));
    list->next=NULL;
    // ����ָ��s�����������x
    LNode * s;
    int x;
    printf("�����룺");
    scanf("%d",&x);
    while (x!=999) {
        s =(LNode*) malloc(sizeof(LNode));
        s->data=x;
        s->next=list->next;
        list->next=s;
        printf("�����룺");
        scanf("%d",&x);
    }
     return list;
}

//���������
void printList(LinkList &L){
    LinkList q;
    q = L->next;
    while(q){
        printf("%d ",q->data);
        q = q->next;
    }
}

// ��ȡA��B�Ľ���
void Inter_src(LinkList A,LinkList B) {
    if (A == NULL || B == NULL) {
        printf("AnBΪ�գ�");
    }
    LNode *pre,*p;
    // p�ڵ��ʾ��ǰ�ڵ�
    pre=A;
    // q�ڵ��ʾ��һ���ڵ�
    p = pre->next;
    while (p) {
        // ������Բ��ð�ֵ���ҵķ���,���ڵĻ������ظýڵ㣬�����ڵĻ������صĶ���NULL���򽫸ýڵ�ɾ��
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

// ��ȡA��B�Ĳ���
void Merge_sec(LinkList A,LinkList B) {
    if (A == NULL || B == NULL) {
        printf("AnBΪ�գ�");
    }
    LNode *p;
    // p�ڵ�ָ���һ���ڵ�
    p=B->next;
    while (p) {
        // ������Բ��ð�ֵ���ҵķ���,���ڵĻ������ظýڵ㣬�����ڵĻ������صĶ���NULL����������ڲ���ͷ�巨�������A������
        if (!LocateElem(B,p->data)) {
            if(Insert_LinkList(A,p->data)){
                p =p->next;
            }
        }
    }
}