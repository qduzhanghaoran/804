#include <stdio.h>
typedef int ELemType;
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