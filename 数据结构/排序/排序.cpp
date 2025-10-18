#include <stdio.h>
#include <stdlib.h>
#include "../树与二叉树/BitTree.h"
#include "../链表/List.h"
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
        if (A[min] != i)
            ; // 交换
    }
}

void HeadAdjust(ElemType A[], int k, int len)
{
    // 对元素k为根的子树进行调整
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])
            i++;
        if (A[0] >= A[i])
            break;
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
}
void BuildMaxHeap(ElemType A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len);
    }
}

void HeapSort(ElemType A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        // 输出栈顶元素
        // 与堆底元素进行交换
        HeadAdjust(A, 1, i - 1);
    }
}

// 链表的选择排序
void selectSort_link(LinkList &L)
{
    LNode *h = L, *p, *q, *r, *s;
    L = NULL;
    while (h != NULL)
    {
        p = s = h;
        q = r = NULL;
        // 指针s和r记忆最大节点和他的前驱，p是工作指针，q为前驱指针；
        while (p != NULL)
        {
            if (p->data > s->data)
            {
                s = p;
                r = q;
            }
            q = p;
            p = p->next;
        }

        if (s == h)
            h = h->next;
        else
            r->next = s->next;
        s->next = L;
        L = s; // 头插法 升序
    }
}

bool IsMinHeap(ElemType A[], int len)
{
    // 使用排除的思想
    // 因为要比较两个孩子先判断一下单双分支
    if (len % 2 == 0)
    {
        if (A[len / 2] > A[len])
            return false;
        for (int i = len / 2 - 1; i > 0; i--)
        {
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                return false;
        }
    }
    else
    {
        for (int i = len / 2; i > 0; i--)
        {
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                return false;
        }
    }
}

void Merge(ElemType A[], int low, int mid, int high)
{
    int B[MaxSize];
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[i++];
}
void MergeSort(ELemType A[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}