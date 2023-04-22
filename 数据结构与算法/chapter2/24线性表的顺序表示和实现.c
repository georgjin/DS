#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int *elem;
    int length;
} SqList;
// ��ʼ��˳���
int InitList(SqList *L)
{
    L->elem = (int *)malloc(MAXSIZE * sizeof(int));
    if (!L->elem)
        return 0;
    L->length = 0;
    return 1;
}
// ˳���Ĳ���
int ListInsert(SqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1) // i�ĺϷ�ֵΪ1<=i<=L->length+1
        return 0;
    if (L->length >= MAXSIZE) // ˳�������
        return 0;
    for (int j = L->length; j >= i; j--) // ����i��Ԫ�ؼ�֮���Ԫ�غ���
        L->elem[j] = L->elem[j - 1];     // ����i��Ԫ�ؼ�֮���Ԫ�غ���
    L->elem[i - 1] = e;                  // ��e���뵽��i��λ��
    L->length++;
    return 1;
}
// ˳����ȡֵ
int GetElem(SqList L, int i, int *e)
{
    if (i < 1 || i > L.length)
        return 0;
    *e = L.elem[i - 1];
    return 1;
}
// ˳���Ĳ���
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}
// ˳����ɾ��
int ListDelete(SqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
        return 0;
    *e = L->elem[i - 1];
    for (int j = i; j < L->length; j++)
        L->elem[j - 1] = L->elem[j];
    L->length--;
    return 1;
}
// ˳���ı���
void ListTraverse(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.elem[i]);
}

int main()
{
    SqList L;
    int e;
    InitList(&L);
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    ListInsert(&L, 5, 5);
    ListInsert(&L, 6, 6);
    ListInsert(&L, 7, 7);
    if (LocateElem(L, 9))
        printf("λ��Ϊ%d", LocateElem(L, 3));
    else
        printf("��Ԫ�ز�����");
    ListTraverse(L);
    return 0;
}