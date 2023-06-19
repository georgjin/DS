#include <stdio.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF * 2 - 1

typedef struct
{
    int bit[MAXBIT];
    int start;
} HCodeType; /* ����ṹ�� */
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
} HNodeType; /* ���ṹ�� */

void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
    int i, j, m1, m2, x1, x2;
    for (i = 0; i < 2 * n - 1; i++)
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].lchild = -1;
    } /* end for */

    for (i = 0; i < n; i++)
    {
        printf("Please input weight of leaf node %d: \n", i);
        scanf("%d", &HuffNode[i].weight);
    } /* end for */

    for (i = 0; i < n - 1; i++)
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
            {
                m2 = HuffNode[j].weight;
                x2 = j;
            }
        } /* end for */
        HuffNode[x1].parent = n + i;
        HuffNode[x2].parent = n + i;
        HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n + i].lchild = x1;
        HuffNode[n + i].rchild = x2;

        printf("x1.weight and x2.weight in round %d: %d, %d\n", i + 1, HuffNode[x1].weight, HuffNode[x2].weight); /* ���ڲ��� */
        printf("\n");
    }
}

int main(void)
{
    HNodeType HuffNode[MAXNODE];     /* ����һ�����ṹ������ */
    HCodeType HuffCode[MAXLEAF], cd; /* ����һ������ṹ�����飬 ͬʱ����һ����ʱ���������������ʱ����Ϣ */
    int i, j, c, p, n;
    printf("Please input n:\n");
    scanf("%d", &n);
    HuffmanTree(HuffNode, n);

    for (i = 0; i < n; i++)
    {
        cd.start = n - 1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1) /* �������� */
        {
            if (HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--; /* �����ĵ�һλ */
            c = p;
            p = HuffNode[c].parent; /* ������һѭ������ */
        }                           /* end while */

        for (j = cd.start + 1; j < n; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];
        }
        HuffCode[i].start = cd.start;
    } /* end for */

    for (i = 0; i < n; i++)
    {
        printf("%d 's Huffman code is: ", i);
        for (j = HuffCode[i].start + 1; j < n; j++)
        {
            printf("%d", HuffCode[i].bit[j]);
        }
        printf("\n");
    }
    return 0;
}
