#define MaxSize 50
#define ELemType int

typedef struct BitNode
{
    /* data */
    ELemType data;
    struct BitNode *lchild, *rchild;
} BitNode, *BiTree;

// 二叉树的遍历

void visit(BiTree T); // 便利
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void LevelOrder(BiTree T);

// 线索二叉树
typedef struct ThreadNode
{
    /* data */
    ELemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(BitNode *p);//在中序遍历的基础上查找节点的前驱

void InTread(ThreadTree T);//中序遍历二叉树一次遍历
void CreatInThread(ThreadTree T);

//WD
int High_D(BiTree T);
int High_C(BiTree T);
bool IsComplete(BiTree T);