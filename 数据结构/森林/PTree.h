#define MAX_TREE_SIZE 100
#define ElemType int
typedef struct{
    ElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree; //双亲表示法

//孩子表示法

//孩子兄弟表示法

typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;