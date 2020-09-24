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

// ɾ��ָ��λ�õ�Ԫ��
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