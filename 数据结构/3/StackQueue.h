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

