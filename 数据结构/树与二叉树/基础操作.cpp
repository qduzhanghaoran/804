#include <stdio.h>
#include <cstdlib>
#include "BitTree.h"
#include "../数组队列/StackQueue.h"
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

void PostOrderIterative1(BiTree T) // 非递归
{
    // 双栈
    BiTree stack1[MaxSize];
    BiTree stack2[MaxSize];
    int top1 = -1;
    int top2 = -1;
    BiTree p;
    stack1[++top1] = T;
    while (top1 >= 0)
    {
        stack2[++top2] = stack1[top1--];
        p = stack2[top2];
        if (p->lchild)
            stack1[++top1] = p->lchild;
        if (p->rchild)
            stack1[++top1] = p->rchild;
    }
    while (top2 >= 0)
    {
        p = stack2[top2--];
        visit(p);
    }
}

void PostOrderIterative2(BiTree T) // 非递归
{
    // 单栈
    visitedNode s[MaxSize];
    int top = -1;
    BiTree p = T;   // 下一个入栈的
    visitedNode vd; // 当前访问要入栈
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
        } // 左子树入栈
        vd = s[top];
        if (vd.node->rchild != NULL && vd.tag == false)
        {
            top--;
            vd.tag = true;
            s[++top] = vd;
            p = vd.node->rchild;
        }
        else
        {
            top--;
            visit(vd.node);
            p = NULL; // visit结束下一个要出栈
        }
    }
}
void LevelOrder(BiTree T)
{
    SqQueue Q;
    InitQueue(Q);
    // EnQueue(Q, T); //函数参数数据类型报错 方便起见注释掉了
    BiTree p;
    while (!isEmpty(Q))
    {
        // DeQueue(Q, p);  //函数参数数据类型报错 方便起见注释掉了
        visit(p);
        if (p->lchild != NULL)
            ;
        // EnQueue(Q, p->lchild);  //函数参数数据类型报错 方便起见注释掉了
        if (p->rchild != NULL)
            ;
        // EnQueue(Q, p->rchild);  //函数参数数据类型报错 方便起见注释掉了
    }
}

// 线索二叉树寻找前驱节点
BitNode *p; // 寻找p的前驱节点
BitNode *final;
BitNode *pre1;
void visit(BitNode *q)
{
    // 中序遍历使用visit函数
    if (p == q)
        final = pre1;
    else
        pre1 = q;
}

ThreadNode *pre2;
void InTread(ThreadTree T)
{
    if (T != NULL)
    {
        InTread(T->lchild);
        // visit()
        if (T->lchild == NULL)
        {
            T->lchild = pre2;
            T->ltag = 1;
        }
        if (pre2 != NULL && pre2->rchild == NULL)
        {
            pre2->rchild = T;
            pre2->rtag = 1;
        }
        pre2 = T;
        InTread(T->rchild);
    }
}
void CreatInThread(ThreadTree T)
{
    if (T != NULL)
    {
        InTread(T);
        pre2->rchild = NULL;
        pre2->rtag = 1;
    }
}

/*
先序线索化的时候
visit(T)                     对T->child明确之后
preThread(T->lchild)         下一步对其线索化会出现环
preThread(T->rchild)

我们要增加条件
if(T->ltag==0)
    preThread(T->lchild)
*/
