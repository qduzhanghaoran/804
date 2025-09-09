#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "../数组队列/StackQueue.h"

//邻接表 BFS
void BFS(ALGraph G, int i)
{
    // 变量定义
    int v, w;
    ArcNode *p;
    SqQueue Q;
    // visited(i);

    visited[i] = true;
    // EnQueue(Q,i);
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
            BFS(G, i);
    }
}