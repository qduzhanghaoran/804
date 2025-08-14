#define MaxSize 50
#define ELemType int

//顺序栈
typedef struct{
    ELemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &s);
bool StackEmpty(SqStack s);
bool Push(SqStack &s,ELemType e);
bool Pop(SqStack &s,ELemType &e);
bool GetTop(SqStack s,ELemType &x);

//链栈
typedef struct Linknode
{
    /* data */
    ELemType data;
    struct Linknode *next;
}LiStack;

/*
链栈使用单链表，所有操作在表头进行。
要求没有表头，Lhead指向栈顶元素
优点：便于多个栈共享存储空间和提高效率
*/

//队列
//队列顺序存储
#define MaxSize 50
typedef struct 
{
    /* data */
    ELemType data[MaxSize];
    int front,rear;
    int tag;//王道T1
}SqQueue;

//循环队列

void InitQueue(SqQueue &Q);
bool isEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q,ELemType x);
bool DeQueue(SqQueue &Q,ELemType &x);

//队列的链式存储
//先声明链表结构 再定义链式队列
typedef struct LinkNode
{
    /* data */
    ELemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct 
{
    /* data */
    LinkNode *front,*rear;
}LinkQueue;

void InitLinkQueue(LinkQueue &Q);
bool IsEmptyLinkQueue(LinkQueue Q);
bool EnLinkQueue(LinkQueue &Q,ELemType x);
bool DeLinkQueue(LinkQueue &Q,ELemType &x);


//WD

typedef struct{
    ELemType stack[MaxSize];
    int top[2];
}stk;//共享栈

int push_stk(stk s,int i,ELemType x);
int pop_stk(stk s,int i);

int EnQueue_1(SqQueue &Q,ELemType x);
int DeQueue_1(SqQueue &Q,ELemType &x);//使用tag标志避免浪费