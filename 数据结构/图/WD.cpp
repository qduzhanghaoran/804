#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "../数组队列/StackQueue.h"
int IsExistEL(MGraph G)
{
    int degree, i, j, count = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        degree = 0;
        for (int j = 0; j < G.vexnum; j++)
            degree += G.edge[i][j];
        if (degree % 2 != 0)
            count++;
    }
    if (count < 2 && count % 2 == 0)
        return 1;
    else
        return 0;
}

int printKVertices(MGraph G)
{
    int indegree, outdegree;
    int count = 0;
    int i, j;
    for (i = 0; i < G.vexnum; i++)
    {
        indegree = 0;
        outdegree = 0;
        for (j = 0; j < G.vexnum; j++) // 计算入度
            if (G.edge[j][i] != 0)
                indegree++;
        for (j = 0; j < G.vexnum; j++)
            if (G.edge[i][j] != 0)
                outdegree++;
        if (outdegree > indegree)
            count++;
    }
    return count;
}

bool isTree(ALGraph G)
{
    int visited[MaxVertexNum];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    int vexNum = 0, arcNum = 0;
    DFS_isTree(G, 1, vexNum, arcNum, visited);
    if (vexNum == G.vexnum && arcNum == 2 * (G.vexnum - 1)) // 访问完成所有的顶点并且访问的边数是n-1
        return true;
    else
        return false;
}
void DFS_isTree(ALGraph G, int i, int &vexNum, int &arcNum, int visited[])
{
    visited[i] = true;
    vexNum++;
    ArcNode *p;
    int w;
    for (p = G.vertices[i].firstarc; p; p = p->nextarc)
    {
        arcNum++;
        w = p->adjvex;
        if (!visited[w])
            DFS_isTree(G, i, vexNum, arcNum, visited);
    }
}

bool DFS_Trace(ALGraph G, int i, int j)
{
    if (i == j)
        return true;
    visited[i] = true;
    ArcNode *p;
    for (G.vertices[i].firstarc; p; p = p->nextarc)
    {
        if (visited[p->adjvex] == false)
        {
            visited[p->adjvex] = true;
            DFS_Trace(G, p->adjvex, j);
        }
    }
    return false;
}
bool BFS_Trace(ALGraph G, int i, int j)
{
    if (i == j)
        return true;
    SqQueue Q;
    InitQueue(Q);
    visited[i] = true;
    EnQueue(Q, i);
    ArcNode *p;
    int w;
    while (!isEmpty(Q))
    {
        DeQueue(Q, w);
        for (p = G.vertices[w].firstarc; p; p = p->nextarc)
        {
            if (p->adjvex == j)
                return true;
            if (!visited[p->adjvex])
                visited[p->adjvex] = true;
        }
    }
    return false;
}

void findPath(ALGraph G, int i, int j, int path[], int d)
{
    visited[i] = true;
    ArcNode *p;
    path[d] = i;
    for (p = G.vertices[i].firstarc; p; p = p->nextarc)
    {
        if (p->adjvex == j)
        {
            for (int m = 0; m <= d; m++)
                printf("%d ", path[m]);
        }
        if (!visited[p->adjvex])
        {
            findPath(G, p->adjvex, j, path, d + 1);
        }
    }
    visited[i] = false;
}