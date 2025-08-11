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

bool SearchExchangeInsert(ELemType A[], ELemType x, int n)
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
            if ((rightA - leftA + 1) % 2 != 0)
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
            if ((rightA - leftA + 1) % 2 != 0)
            {
                rightA = midA;
                leftB = midB;
            }
            else
            {
                rightA = midA;
                leftB = midB + 1;
            }
        }
    }

    return A[midA] < B[midB] ? A[midA] : B[midB];
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

void Del_x_1(LinkList &L, ELemType x)
{
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

LinkList Delete_Min(LinkList &L)
{
    LNode *p = L->next;
    LNode *pre = L;
    LNode *Minpre = L;
    LNode *Min = p;

    while (p != NULL)
    {
        if (p->data < Min->data)
        {
            Min = p;
            Minpre = pre;
        }
        pre = p;
        p = p->next;
    }

    Minpre->next = Min->next;
    free(Min);
    return L;
}

LinkList reverse_Linklist_1(LinkList L)
{
    // 头插法逆转链表
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}
LinkList reverse_Linklist_2(LinkList L)
{
    // 使用三个指针操作；
    LNode *pre, *p = L->next, *r = p->next;
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

bool Delete_same(LinkList &L)
{
    if (L == NULL)
        return false;

    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;
    while (p->next != NULL)
    {
        q = p->next;
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}

LinkList get_Common(LinkList A, LinkList B)
{
    LNode *p = A->next, *q = B->next, *r, *s;
    LNode *C = (LNode *)malloc(sizeof(LNode));
    r = C;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data)
            q = q->next;
        else
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}

LinkList Union(LinkList &A, LinkList &B)
{
    LNode *pa = A->next, *pb = B->next;
    LNode *pc = A, *q;
    LNode *u;
    while (pa && pb)
    {
        if (pa->data == pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data)
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else
        {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa)
    {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb)
    {
        u = pb;
        pb = pb->next;
        free(u);
    }

    pc->next = NULL;
    free(B);
    return A;
}

bool pattern(LinkList A, LinkList B)
{
    LNode *p = A;
    LNode *q = B;
    LNode *pre = A;
    while (pre)
    {
        if (!q)
            return true;
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            q = B;
            pre = pre->next;
            p = pre;
        }
    }
    return false;
}

DLinkList Locate(DLinkList &L, ELemType x)
{
    DNode *p = L->next, *q;
    while (p && p->data != x)
        p = p->next;
    if (!p)
        exit(0);
    else
    {
        p->fre++;
        if (p->prior == L || p->prior->fre > p->fre)
            return p;
        if (p->next != NULL)
        {
            p->next->prior = p->prior;
            p->prior->next = p->next;
        }
        q = p->prior;
        while (q != L && q->fre <= p->fre)
        {
            q = q->prior;
        }
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}

LNode *Converse(LNode *L, int k)
{
    int n = 1;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    p->next = L; // 形成循环链表

    for (int i = 1; i <= n - k; i++)
    {
        p = p->next;
    }
    L = p->next;
    p->next = NULL;
    return L;
}

bool FindLoop(LinkList L)
{
    LNode *fast = L, *slow = L;
    while (fast != NULL && fast->next != NULL) // q走的是两步
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int find_k(LinkList L, int k) // 17
{
    LNode *slow = L, *fast = L->next;
    for (int i = 1; i <= k; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    if (slow == NULL)
        return 0;
    printf("%d", slow->data);
    return 1;
}

// T16
int Listlen(T16_Node *head)
{
    int len = 0;
    while (head->next != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

T16_Node *find_list(T16_Node *list1, T16_Node *list2)
{
    int m, n;
    T16_Node *p, *q;
    m = Listlen(list1);
    n = Listlen(list2);

    for (p = list1; m > n; m--)
        p = p->next;
    for (q = list2; m < n; n--)
        q = q->next;
    while (p->next != NULL && p->next != q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->next;
}