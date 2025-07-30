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

bool SearchExchangeInsert(ELemType A[], ELemType x)
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

int M_Search_On(int A[], int B[], int n)
{

    // 对两个长度为n的序列按照从小到大排序依次访问
    // 并不是先合并
    int ans;

    int a, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[a] <= B[b])
        {
            ans = A[a++];
        }
        else
        {
            ans = A[b++];
        }
    }
    return ans;
}

int M_Search_logn(int A[], int B[], int n)
{
    // 折半查找
    /*A的中位数为mida，B的中位数为midb.
    如果mida==midb 中位数为mida=midb
    如果mida<midb 中位数位于mida->midb之间 舍弃A中较小的一般 B中较大的一半
    同理mida>midb
    并且每个数组都设置两对首尾指针
    */

    int leftA, leftB = 0;
    int rightA, rightB = n - 1;
    int midA, midB;
    while (leftA != rightA || leftB != rightB)
    {
        midA = (leftA + rightA) / 2;
        midB = (leftB + rightB) / 2;

        if (A[midA] == B[midB])
            return A[midA];
        if (A[midA] < B[midB])
        {
            if ((rightA - lefeA + 1) % 2 != 0)
            {
                leftA = midA;
                rightB = midB;
            }
            else
            {
                leftA = midA + 1;
                rightB = midB;
            }
        }
        else
        {
            if ((rightA - lefeA + 1) % 2 != 0)
            {
                rightA = midA;
                leftB = midB;
            }
            else
            {
                rightA = midA;
                rleftB = midB + 1;
            }
        }
    }

    return A[midA] < B[midB] ? A[midA] : B[midB]
}

int Majority(int A[], int n)
{
    // 数组中出现次数大于n/2的为主元素
    // 查找数组中的主元素
    // 使用count来计数，假设c为主元素遇到重复加1，不重复-1，最终肯定会保留计数
    // 其他非主元素由于小于n/2最终肯定会重新计
    // 也可以使用辅助数组
    int c, count = 1;
    c = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] == c)
            count++;
        else
        {
            if (count > 0)
                count--;
            else
            {
                c = A[i];
                count = 1;
            }
        }
    }

    if (count > 0)
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == c)
                count++;
        }
    }
    if (count > n / 2) // 需要判断是否为n/2 例如 A=[0,5,5,3,5,1,5,7]
        return c;
    else
        return -1;
}

int findMissMid(int A[], int n)
{
    // 寻找从未出现的最小正整数
    // 使用空间换时间
    // 使用辅助数组size=n即可

    int temp[n + 1];

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0 && A[i] <= n)
        {
            temp[A[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (temp[i] == 0)
        {
            return i;
        }
    }
}