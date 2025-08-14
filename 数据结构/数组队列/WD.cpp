#include <stdio.h>
#include <cstdlib>
#include "StackQueue.h"

int push_stk(stk s, int i, ELemType x)
{
    if (i < 0 || i > 1)
        exit(0);
    if (s.top[1] - s.top[0] == 1)
    {
        // 栈满
        return 0;
    }
    else
    {
        switch (i)
        {
        case 0:
            /* code */
            s.stack[++s.top[0]] = x;
            return 1;
            break;

        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
            break;
        }
    }
}
int pop_stk(stk s, int i)
{
    if (i < 0 || i > 1)
        exit(0);
    switch (i)
    {
    case 0:
        /* code */
        if (s.top[0] == -1)
        {
            // 栈空
            return 0;
        }
        else
        {
            return (s.stack[s.top[0]--]);
        }
        break;

    case 1:
        if (s.top[1] == MaxSize - 1)
        {
            // 栈空
            return 0;
        }
        else
        {
            return (s.stack[s.top[1]++]);
        }
        break;
    }
}

int EnQueue_1(SqQueue &Q,ELemType x)
{
    if(Q.front==Q.rear && Q.tag==1)
    return 0;

    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    Q.tag=1;//可能满
    return 1;
}
int DeQueue_1(SqQueue &Q,ELemType &x)
{
    if(Q.front==Q.rear && Q.tag==0)
    return 0;

    x=Q.data[Q.front];
    Q.front=(Q.front-1)%MaxSize;
    Q.tag=0;
    return 1;
}