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
    BiTree p = bt;

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
        else
        {
            if (vd.node->data == x)
            {
                int i = top - 1;
                while (i >= 0)
                {
                    printf("%d ", s[i--].node->data);
                }
            }
            else
            {
                top--;
                p = NULL;
            }
        }
    }
}

void PreToPost(ELemType pre[], int l1, int h1, ELemType post[], int l2, int h2)
{
    // 满二叉树先序遍历去除根节点之后的左右子树是平分的
    // 先序遍历第一个节点是后序遍历的最后一个节点
    // 使用递归

    // pre:  A B D E C F G
    // post: D E B F G C A
    int half;
    if (h1 >= l1)
    {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1); // 递归左子树
        PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1); // 递归右子树
    }
}

void DsonNodes(BiTree T)
{
    if (!T)
        return;
    if (T->lchild != NULL && T->rchild != NULL)
        count_T5++;
    DsonNodes(T->lchild);
    DsonNodes(T->rchild);
}

void swap(BiTree T)
{
    // 交换左右子树，前序和后序遍历都可以
    BiTree temp;
    swap(T->lchild);
    swap(T->rchild);

    // 交换
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
}

ELemType PreNode(BiTree T, int k)
{
    // 先序遍历中第k个值
    // 在先序遍历的基础上进行改造

    i_T7++;
    if (i_T7 == k)
        return T->data;

    PreNode(T->lchild, k);
    PreNode(T->rchild, k);
}

void DeleteNode(BiTree &T)
{
    if (T)
    {
        DeleteNode(T->lchild);
        DeleteNode(T->rchild);
        free(T);
    }
}

void search(BiTree &T, ELemType x)
{
    BiTree Q[MaxSize];
    int front, rear = -1;
    BiTree t;
    Q[++rear] = T;
    while (rear > front)
    {
        t = Q[++front];
        if (t->lchild)
        {
            if (t->lchild->data == x)
            {
                DeleteNode(t->lchild);
                t->lchild = NULL;
            }
            else
            {
                Q[++rear] = t->lchild;
            }
        }

        if (t->rchild)
        {
            if (t->rchild->data == x)
            {
                DeleteNode(t->rchild);
                t->rchild = NULL;
            }
            else
            {
                Q[++rear] = t->rchild;
            }
        }
    }
}

void linkLeaf(BiTree T,BiTree head)
{
    //使用先序遍历
    if(!T) return;
    BiTree pre=NULL;

    if(T->lchild==NULL && T->rchild==NULL)
    {
        if(pre==NULL)
        {
            pre=T;
            head=T;
        }
        else
        {
            pre->lchild=T;
            pre=T;
        }
    }
    linkLeaf(T->lchild,head);
    linkLeaf(T->rchild,head);
    pre->rchild=NULL;
}

