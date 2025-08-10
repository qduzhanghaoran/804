#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ELemType int

typedef struct
{
    /* data */
    ELemType *elem; // 存储空间基址
    int length;
    int listsize;
} SqList;

void InitList_Sq(SqList *L);
void ListInsert_Sq(SqList *L, int i, ELemType e);
void Union();
bool ListDelete(SqList &L, int i, ELemType &e);
int LocateElem(SqList &L, ELemType e);

// WD
bool Del_Min(SqList &L, ELemType &e);
bool Reverse(SqList &L);
bool Del_all_x(SqList &L, ELemType e);

bool Del_same(SqList &L);
bool Merge(SqList &L1, SqList &L2, SqList &L);
bool Reverse_array(ELemType A[], int left, int right, int arrarSize);
bool Exchang(ELemType A[], int m, int n, int arraysize);
bool SearchExchangeInsert(ELemType A[], ELemType x,int n);
int M_Search_On(int A[], int B[], int n);
int M_Search_logn(int A[], int B[], int n);
int Majority(int A[], int n);
int findMissMid(int A[], int n);

// 单链表
typedef struct LNode
{
    /* data */
    ELemType data;
    struct LNode *next;
} LNode, *LinkList;

int Length(LinkList L);
LNode *GetElem(LinkList L,int i);
bool LinklistInsert(LinkList L,int i,ELemType e);
bool LinkListDelete(LinkList &L,int i,ELemType &e);
LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);

//双链表
typedef struct DNode
{
    /* data */
    ELemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//同理插入删除 只是对指针操作不同


//静态链表
#define MAX 50
typedef struct 
{
    /* data */
    ELemType data;
    int next;
}SLinkList[MAX];

//WD
void Del_x_1(LinkList &L,ELemType x);
LinkList Delete_Min(LinkList &L);
LinkList reverse_Linklist_1(LinkList L);
LinkList reverse_Linklist_2(LinkList L);
bool Delete_same(LinkList &L);
LinkList get_Common(LinkList A,LinkList B);
LinkList Union(LinkList &A,LinkList &B);
bool pattern(LinkList A, LinkList B);
