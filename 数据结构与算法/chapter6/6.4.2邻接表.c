#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode
{
    int adjvex;              // 邻接点在顶点数组中的下标
    struct ArcNode *nextarc; // 指向下一个邻接点的指针
    int weight;              // 边的权值（可根据需求修改）
} ArcNode;

typedef struct VNode
{
    int data;          // 顶点的数据（可根据需求修改）
    ArcNode *firstarc; // 指向第一个邻接点的指针
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;   // 图的顶点数组
    int vexnum, arcnum; // 顶点数和边数
} ALGraph;

// 创建无向图
void CreateALGraph(ALGraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d,%d", &G->vexnum, &G->arcnum);
    printf("请输入顶点信息：");
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%d", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL; // 初始化邻接表
    }
    printf("请输入每条边的两个顶点及权值：\n");
    for (k = 0; k < G->arcnum; k++)
    {
        scanf("%d,%d,%d", &i, &j, &w);

        // 创建边结点并插入到邻接表中
        ArcNode *arcNode1 = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode1->adjvex = j;
        arcNode1->weight = w;
        arcNode1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = arcNode1;

        ArcNode *arcNode2 = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode2->adjvex = i;
        arcNode2->weight = w;
        arcNode2->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = arcNode2;
    }
}

// 输出邻接表表示的图
void DispAdj(ALGraph G)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
    {
        printf("%d: ", G.vertices[i].data);
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
            printf("%d(%d) ", G.vertices[p->adjvex].data, p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);
    DispAdj(G);
    return 0;
}
