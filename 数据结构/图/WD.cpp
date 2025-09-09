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

