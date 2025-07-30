#include <stdio.h>
#include <cstdlib>
#include "List.h"
void InitList_Sq(SqList *L)
{
    // 构造空表
    L->elem = (ELemType *)malloc(LIST_INIT_SIZE * sizeof(ELemType));
    if (!L->elem)
        printf("分配失败");
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

void ListInsert_Sq(SqList *L, int i, ELemType e)
{
    // 顺序表L中第i个位置插入新元素e
    if (i < 1 || i > L->length + 1)
        printf("i 不合法");
    if (L->length >= L->listsize)
    {
        int *newbase = (ELemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ELemType));
        if (!newbase)
            printf("分配失败");
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    int *q;
    q = &(L->elem[i - 1]);

    for (int *p = &(L->elem[L->length - 1]); p >= q; p--)
    {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
}

bool ListDelete(SqList &L, int i, ELemType &e)
{
    // 在顺序表中删除第i个元素 并输出为e

    if (i < 1 || i > L.length)
        return false;
    e = L.elem[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
        L.length--;
    }
    return true;
}

int LocateElem(SqList &L, ELemType e)
{
    // 按值查找
    int i = 0;
    for (i; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
}