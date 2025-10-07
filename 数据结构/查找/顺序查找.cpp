#include <stdio.h>
#include <stdlib.h>
#include "../树与二叉树/BitTree.h"
#define ElemType int
typedef struct
{
    ELemType *elem;
    int Tablen;
} SSTable;
int search_Seq(SSTable ST, ELemType key)
{
    int i;
    ST.elem[0] = key;
    for (i = ST.Tablen; ST.elem[i] != key; --i)
        ;
    return i;
}

int Binary_Search(SSTable L, ELemType key)
{
    int low = 0, high = L.Tablen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int BinSearchRec(SSTable L, ELemType key, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] < key)
            BinSearchRec(L, key, mid + 1, high);
        else
            BinSearchRec(L, key, low, mid - 1);
    }
    return 0;
}

// BST

BitNode *BST_search(BiTree T, ElemType key)
{
    while (T != NULL && T->data != T->data)
    {
        if (key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

bool BST_insert(BiTree &T, ElemType key)
{
    if (T == NULL)
    {
        T = (BiTree)malloc(sizeof(BitNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    }
    else if (key < T->lchild->data)
    {
        BST_insert(T->lchild, key);
        return true;
    }
    else
    {
        BST_insert(T->rchild, key);
        return true;
    }
}

// JudgeBST
ElemType predata = -32767;
int JudgeBST(BiTree bt)
{
    // 利用性质二叉排序树的中序遍历是递增序列
    int bl, br;
    if (bt == NULL)
        return 1;
    else
    {
        // 中序遍历
        bl = JudgeBST(bt->lchild);

        if (!(bl) || bt->data < predata)
            return 0;
        predata = bt->data;

        br = JudgeBST(bt->rchild);
        return br;
    }
}

void Judge_AVL(BiTree T, int &balance, int &h)
{
    // 平衡标记balance bt是平衡二叉树为1
    int bl, br, hl, hr = 0;
    if (T == NULL)
    {
        h = 0;
        balance = 1;
    }
    else if (T->lchild == NULL && T->rchild == NULL)
    {
        h = 1;
        balance = 1;
    }
    else
    {
        Judge_AVL(T->lchild, bl, hl);
        Judge_AVL(T->rchild, br, hr);
        h = (hl > hr ? hl : hr) + 1;
        if (abs(hl - hr) < 2)
            balance = bl & br;
        else
            balance = 0;
    }
}

BiTree Search_Small_k(BiTree T, int k)
{
    if (k < 1 || k > T->count)
        return NULL;

    if (T->lchild->count == k - 1)
        return T;
    else if (T->lchild->count > k - 1)
        return Search_Small_k(T->lchild, k);
    else
        return Search_Small_k(T->rchild, k - (T->lchild->count));
}