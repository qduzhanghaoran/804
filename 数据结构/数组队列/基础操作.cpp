#include <stdio.h>
#include <cstdlib>
#include "StackQueue.h"

void InitStack(SqStack &s)
{
    s.top = -1;
}

bool StackEmpty(SqStack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &s, ELemType e)
{
    if (s.top == MaxSize - 1)
        return false;
    s.data[++s.top] = e;
    return true;
}

bool Pop(SqStack &s, ELemType &e)
{
    if (s.top == -1)
        return false;
    e = s.data[s.top--];
    return true;
}

bool GetTop(SqStack s, ELemType &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top];
    return true;
}

// 循环队列
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, ELemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ELemType &x)
{
    if (isEmpty(Q))
        return false;

    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 链式队列
void InitLinkQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmptyLinkQueue(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

bool EnLinkQueue(LinkQueue &Q, ELemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s; // 保证能链成一个队列
    return true;
}

bool DeLinkQueue(LinkQueue &Q, ELemType &x)//**********
{

    // 空头节点一直存在
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    // 如果只有一个节点了 Q.front指向了rear后的NULL
    if (Q.rear == p)
        Q.front = Q.rear;
    free(p);
    return true;
}