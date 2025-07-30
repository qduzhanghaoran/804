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
bool SearchExchangInsert(ELemType A[], ELemType x);