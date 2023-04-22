#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data; //������
    struct LNode *next;//ָ����
}LNode,*LinkList;

//ע��:LinkList L �ǵ������ͷָ��,����ͷ���
// LNode *p ��ָ�������ĳ���ڵ��ָ��
// Ϊ�˷��㴦���ڵ�����ĵ�һ�����֮ǰ����һ����㣬��Ϊͷ���
// ͷ�ڵ�->��Ԫ�ڵ㣨�����һ������Ԫ��a1��->...
// ͷ�ڵ������
// 1. ������Ԫ�ڵ�Ĵ���
// 2. ���ڿձ�ͷǿձ��ͳһ����

//��ʼ��������
int InitList(LinkList *L)
{
    LinkList p = (LinkList)malloc(sizeof(LNode)); //����ͷ���
    if(!p) return 0; //����ʧ��
    p->next = NULL; //ͷ���ָ�����ÿ�
    return 1;
}

//ȡֵ
int GetElem(LinkList L,int i,int *e)//�ڴ�ͷ�ڵ�ĵ�����L�и������i��ȡԪ�ص�ֵ����e����
{
    LinkList p = L->next; //pָ����Ԫ�ڵ�
    int j = 1;
    while (p && j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i) return 0; //��i��Ԫ�ز�����
    *e = p->data;
    return 1;
}
//����
LinkList LocateElem(LinkList L,int e)//�ڴ�ͷ�ڵ�ĵ�����L�в��ҵ�һ��ֵΪe��Ԫ�أ����������
{
    LinkList p = L->next; //pָ����Ԫ�ڵ�
    while (p && p->data!=e)
    {
        p = p->next;
    }
    return p;
}
//����
int ListInsert(LinkList L,int i,int e)//�ڴ�ͷ�ڵ�ĵ�����L�е�i��λ��֮ǰ����Ԫ��e
{
    LinkList p = L; //pָ��ͷ���
    int j = 0;
    while (p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) return 0; //��i��Ԫ�ز�����
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

int main()
{
    LinkList L;
    InitList(&L); //��ʼ��������
    ListInsert(L,1,1); //�ڵ�����L�ĵ�1��λ�ò���Ԫ��1
    ListInsert(L,2,2); //�ڵ�����L�ĵ�2��λ�ò���Ԫ��2
    ListInsert(L,3,3); //�ڵ�����L�ĵ�3��λ�ò���Ԫ��3
    LinkList p =  LocateElem(L,2); //���ҵ�����L��ֵΪ2��Ԫ��
    printf("%d",p->data); //���������L��ֵΪ2��Ԫ��
}
