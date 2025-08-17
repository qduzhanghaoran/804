#include <stdio.h>
#include <cstdlib>
#include "BitTree.h"
#include "../数组队列/StackQueue.h"
int High_D(BiTree T)
{
    if (!T)
        return 0;
    return High_D(T->lchild) > High_D(T->rchild) ? High_D(T->lchild) + 1 : High_D(T->rchild) + 1;
}

int High_C(BiTree T)
{
    // 使用层次遍历来计算高度
    if (!T)
        return 0;

    int front, rear = -1; // 定义队列
    int last, high = 0;//记录每层最后一个节点的位置
    BiTree Q[MaxSize];
    BiTree p;
    Q[++rear] = T;
    while (front < rear)
    {
        p = Q[++front];
        if (p->lchild != NULL)
            Q[++rear] = p->lchild;
        if (p->rchild != NULL)
            Q[++rear] = p->rchild;
        if (front == last)
        {
            high++;
            last = rear;
        }
    }
    return high;
}