#include <stdio.h>
#include <stdlib.h>
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

void CreateUDN(AMGraph *G)
{
    int i, j, k, w;
    printf("�����붥�����ͱ�����");
    scanf("%d,%d", &G->vexnum, &G->arcnum);
    getchar(); // ������뻺�����Ļ��з�
    printf("�����붥����Ϣ��");
    for (i = 0; i < G->vexnum; i++)
        scanf("%c", &G->vexs[i]);
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j] = MaxInt;
    printf("������ÿ���ߵ��������㼰Ȩֵ��\n");
    for (k = 0; k < G->arcnum; k++)
    {
        scanf("%d,%d,%d", &i, &j, &w);
        G->arcs[i][j] = w;
        G->arcs[j][i] = G->arcs[i][j];
    }
}

// ���
void DispAdj(AMGraph G)
{
    int i, j;
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            if (G.arcs[i][j] != MaxInt)
                printf("%d,%d,%d\n", i, j, G.arcs[i][j]);
    }
}

int main()
{
    AMGraph G;
    CreateUDN(&G);
    DispAdj(G);
    return 0;
}
