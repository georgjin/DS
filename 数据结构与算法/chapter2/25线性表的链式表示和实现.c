#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data; //数据域
    struct LNode *next;//指针域
}LNode,*LinkList;

//注意:LinkList L 是单链表的头指针,不是头结点
// LNode *p 是指向单链表的某个节点的指针
// 为了方便处理，在单链表的第一个结点之前增加一个结点，称为头结点
// 头节点->首元节点（储存第一个数据元素a1）->...
// 头节点的作用
// 1. 便于首元节点的处理
// 2. 便于空表和非空表的统一处理

//初始化单链表
int InitList(LinkList *L)
{
    LinkList p = (LinkList)malloc(sizeof(LNode)); //创建头结点
    if(!p) return 0; //分配失败
    p->next = NULL; //头结点指针域置空
    return 1;
}

//取值
int GetElem(LinkList L,int i,int *e)//在带头节点的单链表L中根据序号i获取元素的值，用e返回
{
    LinkList p = L->next; //p指向首元节点
    int j = 1;
    while (p && j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i) return 0; //第i个元素不存在
    *e = p->data;
    return 1;
}
//查找
LinkList LocateElem(LinkList L,int e)//在带头节点的单链表L中查找第一个值为e的元素，返回其序号
{
    LinkList p = L->next; //p指向首元节点
    while (p && p->data!=e)
    {
        p = p->next;
    }
    return p;
}
//插入
int ListInsert(LinkList L,int i,int e)//在带头节点的单链表L中第i个位置之前插入元素e
{
    LinkList p = L; //p指向头结点
    int j = 0;
    while (p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) return 0; //第i个元素不存在
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

int main()
{
    LinkList L;
    InitList(&L); //初始化单链表
    ListInsert(L,1,1); //在单链表L的第1个位置插入元素1
    ListInsert(L,2,2); //在单链表L的第2个位置插入元素2
    ListInsert(L,3,3); //在单链表L的第3个位置插入元素3
    LinkList p =  LocateElem(L,2); //查找单链表L中值为2的元素
    printf("%d",p->data); //输出单链表L中值为2的元素
}
