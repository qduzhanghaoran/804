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