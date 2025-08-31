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
void PostOrderIterative1(BiTree T); // 非递归 双栈
void PostOrderIterative2(BiTree T); // 非递归 单栈
void LevelOrder(BiTree T);

// 线索二叉树
typedef struct ThreadNode
{
    /* data */
    ELemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(BitNode *p); // 在中序遍历的基础上查找节点的前驱

void InTread(ThreadTree T); // 中序遍历二叉树一次遍历
void CreatInThread(ThreadTree T);

// WD
int High_D(BiTree T);
int High_C(BiTree T);
bool IsComplete(BiTree T);

// 查找祖先
typedef struct
{
    BiTree node;
    bool tag = false; // 记录右儿子是否被访问
} visitedNode;        // 后序遍历——入栈

void Search(BiTree bt, ELemType x);
void PreToPost(ELemType pre[], int l1, int h1, ELemType post[], int l2, int h2);
int count_T5;
void DsonNodes(BiTree T);
void swap(BiTree T);
int i_T7 = 0;
ELemType PreNode(BiTree T, int k);
void DeleteNode(BiTree &T);
void search(BiTree &T, ELemType x);
void linkLeaf(BiTree T,BiTree head); // 链接叶子节点