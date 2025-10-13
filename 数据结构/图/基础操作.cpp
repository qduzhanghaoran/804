#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "../数组队列/StackQueue.h"
#include <math.h>

// 邻接表 BFS
void BFS_1(ALGraph G, int i)
{
    // 变量定义
    int v, w;
    ArcNode *p;
    SqQueue Q;
    // visited(i);

    visited[i] = true;
    EnQueue(Q, i);
    while (!isEmpty(Q))
    {
        DeQueue(Q, v);
        for (p = G.vertices[v].firstarc; p; p = p->nextarc)
        {
            w = p->adjvex;
            if (visited[w] == false)
            {
                // visit(w)
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}
void BFSTraverse(ALGraph G)
{
    SqQueue Q;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    InitQueue(Q);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            BFS_1(G, i);
    }
}

void BFS_2(MGraph G, int i)
{
    // 变量定义
    SqQueue Q;
    int v, w;
    // visit(i)
    visited[i] = true;
    EnQueue(Q, i);
    while (!isEmpty(Q))
    {
        DeQueue(Q, v);
        for (w = 0; w < G.vexnum; w++)
        {
            if (visited[w] == false && G.edge[v][w] != 0)
            {
                // visited(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void BFS_MIN_Distance(ALGraph G, int u)
{
    // d[i]表示从u到i的最短距离
    int d[MaxVertexNum];
    for (int i = 0; i < G.vexnum; i++)
    {
        d[i] = INFINITY; // 无穷
    }
    // BFS
    SqQueue Q;
    ArcNode *p;
    int w;
    visited[u] = true;
    d[u] = 0;
    EnQueue(Q, u);
    while (!isEmpty(Q))
    {
        DeQueue(Q, u); // 公用变量u作为出队数据
        for (p = G.vertices[u].firstarc; p; p = p->nextarc)
        {
            w = p->adjvex;
            if (visited[w] == false)
            {
                visited[w] = true;
                d[w] = d[u] + 1;
                EnQueue(Q, w);
            }
        }
    }
}

void DFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            DFS_1(G, i);
    }
}
void DFS_1(ALGraph G, int i)
{
    // 变量定义
    ArcNode *p;
    int j;
    // visited(i);
    visited[i] = true;
    for (p = G.vertices[i].firstarc; p; p = p->nextarc) // 回退之后遍历下一个节点
    {
        j = p->adjvex;
        if (visited[j] == false)
        {
            //调用函数即访问，在开头标记
            DFS_1(G, j);
        }
    }
}
void DFS_2(MGraph G, int i)
{
    // 变量定义
    int p;
    // visit(i)
    visited[i] = true;
    for (p = 0; p < G.vexnum; p++)
    {
        if (visited[p] == false && G.edge[i][p] == 1)
            DFS_2(G, p);
    }
}

bool TopologicalSort(ALGraph G)
{
    SqStack S;
    InitStack(S);
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].firstarc->adjvex)
    }
}