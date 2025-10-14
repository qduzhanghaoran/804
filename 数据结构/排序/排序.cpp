#include <stdio.h>
#include <stdlib.h>
#include "../树与二叉树/BitTree.h"
#define ElemType int

// 插入排序
void InsertSort(ElemType A[], int n)
{
    int i, j;
    for (int i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i]; // 哨兵
            for (int j = i - 1; A[j] > A[0]; j--)
            {
                A[j + 1] = A[j];
            }
            A[j] = A[0];
        }
    }
}

void InsertSort_half(ElemType A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1, high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--) // 折半查找while循环结束high永远指向比key小的值
            A[j + 1] = A[j];
        A[high + 1] = A[0];
    }
}

void shellsort(ElemType A[], int n)
{
    int dk, i, j;
    for (dk = n / 2; dk >= 1; dk /= 2) // 增量变化，没有特殊要求
    {
        for (i = dk + 1; i <= n; i++)
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                for (j = i - dk; A[j] > A[0] & j > 0; j -= dk)
                {
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}

void BubbleSort(ElemType A[], int n)
{
    ElemType t;
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                t = A[j - 1];
                A[j - 1] = A[j];
                A[j] = t;
                flag = false;
            }
        }
        if (flag == false)
            return; // 如果一次冒泡没有发生交换说明排序完成
    }
}

// 快速排序划分操作
int partition(ELemType A[], int low, int high) // c语言中数组作为参数会退化为指针
{
    ELemType pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(ELemType A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

// WD
void move(ELemType A[], int len)
{
    int i = 0, j = len - 1;
    while (i < j)
    {
        while (i < j && A[i] % 2 == 0)
            i++;
        while (i < j && A[j] % 2 != 0)
            j--;
        // 交换
        if (i < j)
            ; // 交换
    }
}

int kth_elem(int a[], int low, int high, int k)
{
    /*
    最直接的方法就是对数组进行排序然后选择A[K]
    也可以使用小顶堆，每次堆顶都是最小的

    使用更精彩的算法，基于快速排序的划分操作
    划分L[1..m-1]和L[m+1..n]
                low
    如果m==k直接输出
    ...
    */
    int pivot = a[low];
    int i = low, j = high;
    while (low < high)
    {
        while (low < high && a[high] > pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] < pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;

    if (low == k)
        return a[low];
    else if (low > k)
        return kth_elem(a, i, j, k);
    else
        return kth_elem(a, low + 1, j, k - low);
}

void SelectSort(ElemType A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (A[min] !=i)
            ; // 交换
    }
}

