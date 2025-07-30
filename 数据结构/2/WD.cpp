#include <stdio.h>
#include <cstdlib>
#include "List.h"

bool Del_Min(SqList &L, ELemType &e)
{
    // 删除顺序表中的最小值
    if (L.length == 0)
        return false;
    e = L.elem[0];
    int pos = 0; // 记录位置
    for (int i = 1; i < L.length; i++)
    {
        if (L.elem[i] < e)
        {
            e = L.elem[i];
            pos = i;
        }
    }
    L.elem[pos] = L.elem[L.length - 1]; // 空出的位置由最后一个填补
    L.length--;
    return true;
}

bool Reverse(SqList &L)
{
    // 逆转顺序表
    ELemType t;
    for (int i = 0; i < L.length / 2; i++)
    {
        t = L.elem[i];
        L.elem[i] = L.elem[L.length - 1 - i];
        L.elem[L.length - 1 - i] = t; // 交换数据
    }
}

bool Del_all_x(SqList &L, ELemType e)
{
    // 删除所有值为e的值，时间复杂度为O(n)
    int time = 0; // 移动几个

    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            time++;
            continue;
        }

        L.elem[i - time] = L.elem[i];
    }

    L.length -= time;
    return true;
}

bool Del_same(SqList &L)
{
    // 有序顺序表中删除重复元素
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.elem[i] != L.elem[j])
        {
            L.elem[++i] = L.elem[j];
        }
    }
    L.length = i + 1;
    return true;
}

bool Merge(SqList &L1, SqList &L2, SqList &L)
{
    // 将两个有序的顺序表合并到一起

    if (L1.length + L2.length > L.length)
        return false;

    int i, j = 0;
    int t = 0;
    while (i < L1.length && j < L2.length)
    {
        if (L1.elem[i] < L2.elem[j])
        {
            L.elem[t++] = L1.elem[i++];
        }
        else
        {
            L.elem[t++] = L2.elem[j++];
        }
    }

    while (j < L2.length)
    {
        /* code */
        L.elem[t++] = L2.elem[j++];
    }

    while (i < L1.length)
    {
        /* code */
        L.elem[t++] = L1.elem[i++];
    }

    L.length = t;
    return true;
}

bool Reverse_array(ELemType A[], int left, int right, int arrarSize)
{
    // 逆转数组
    if (left >= right || right > arrarSize)
    {
        return false;
    }

    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++)
    {
        ELemType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
    return true;
}
bool Exchang(ELemType A[], int m, int n, int arraysize)
{
    // 交换数组中的两个顺序表
    Reverse_array(A, 0, m + n - 1, arraysize);
    Reverse_array(A, 0, n - 1, arraysize);
    Reverse_array(A, n, m + n - 1, arraysize);
}

bool SearchExchangInsert(ELemType A[], ELemType x, int n)
{
    // 数组中元素有序递增，最高效查找x，如果找到和后继元素交换，否则插入x保持递增
    /*二分查找*/

    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (A[mid] == x && mid != n - 1)
    {
        // 后继元素交换
    }
    if (low > high) // high最终位置接近x并且小于x
    {
        for (int i = n - 1; n > high; i--)
        {
            A[i + 1] = A[i];
        }
        A[high + 1] = x;
    }
    return true;
}