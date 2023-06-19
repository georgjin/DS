#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

// 创建无向图
void CreateALGraph(ALGraph *G)
{
    int i, j, k;
    printf("请输入顶点数和边数：");
    scanf("%d,%d", &G->vexnum, &G->arcnum);
    printf("请输入顶点信息：");
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%d", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    printf("请输入每条边的两个顶点：\n");
    for (k = 0; k < G->arcnum; k++)
    {
        scanf("%d,%d", &i, &j);
        ArcNode *arcNode1 = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode1->adjvex = j;
        arcNode1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = arcNode1;

        ArcNode *arcNode2 = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode2->adjvex = i;
        arcNode2->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = arcNode2;
    }
}

// 深度优先搜索
void DFS(ALGraph G, int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", G.vertices[v].data);
    ArcNode *p = G.vertices[v].firstarc;
    while (p)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visited);
        }
        p = p->nextarc;
    }
}

// 广度优先搜索
void BFS(ALGraph G, int v, bool visited[])
{
    int queue[MaxVertexNum];
    int front = 0, rear = 0;
    visited[v] = true;
    printf("%d ", G.vertices[v].data);
    queue[rear++] = v;
    while (front < rear)
    {
        int w = queue[front++];
        ArcNode *p = G.vertices[w].firstarc;
        while (p)
        {
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = true;
                printf("%d ", G.vertices[p->adjvex].data);
                queue[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);

    bool visited[MaxVertexNum] = {false}; // 记录顶点的访问状态，初始化为false

    printf("深度优先搜索结果：");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            DFS(G, i, visited);
        }
    }

    printf("\n");

    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false; // 重置访问状态
    }

    printf("广度优先搜索结果：");
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i, visited);
        }
    }

    return 0;
}
