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
    int last, high = 0;   // 记录每层最后一个节点的位置
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

bool IsComplete(BiTree T)
{
    BiTree Q[MaxSize];
    int front, rear = -1;
    BiTree q;
    Q[++rear] = T;
    while (front < rear)
    {
        q = Q[++front];
        if (q != NULL)
        {
            Q[++rear] = q->lchild;
            Q[++rear] = q->rchild;
        }
        else
        {
            while (front < rear)
            {
                q = Q[++front];
                if (q)
                    return false;
            }
        }
    }
    return true;
}

void Search(BiTree bt, ELemType x)
{
    visitedNode s[MaxSize];
    int top = -1;
    visitedNode vd;
    BiTree p=bt;

    vd.node = p;
    vd.tag = false;
    s[++top] = vd;
    p = p->lchild;
    while (top >= 0)
    {
        while (p != NULL)
        {
            vd.node = p;
            vd.tag = false;
            s[++top] = vd;
            p = p->lchild;
        }
        vd = s[top];
        if (vd.node->rchild != NULL && vd.tag == false)
        {
            vd.tag = true;
            top--;
            s[++top] = vd;
            p = vd.node->rchild;
        }
        else{
            if(vd.node->data==x)
            {
                int i=top-1;
                while(i>=0)
                {
                    printf("%d ",s[i--].node->data);
                }
            }
            else
            {
                top--;
                p=NULL;
            }
        }
    }
}
