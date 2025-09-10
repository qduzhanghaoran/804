// 图的邻接矩阵存储
#define MaxVertexNum 100
typedef char VertexType; // 顶点
typedef int EdgeType;    // 边
typedef struct
{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum; // 记录图中的顶点数和边数
} MGraph;

// 邻接表
typedef struct ArcNode
{ // 边
    int adjvex;
    struct ArcNode *nextarc;
    // Infotype info;
} ArcNode;
typedef struct VNode
{ // 顶点
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MaxVertexNum];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

/*全程使用AdjList来记录所有的顶点的信息——data和依附于这个顶点的第一条表
对于顶点之间的关系记录所有的边，边的信息有 ①此边指向的顶点是哪一个 下一条边（与其相邻）的是哪一条
图只需要记录顶点和顶点之间的关系
*/

// WD

// EL路径
int IsExistEL(MGraph G);
int printKVertices(MGraph G);

// 图的遍历
bool visited[MaxVertexNum];   // 访问标记数组
void BFS_1(ALGraph G, int i); // 邻接表实现BFS
void BFSTraverse(ALGraph G);
void BFS_2(MGraph G, int i);

// BFS求解非带权图单源最短路径问题
void BFS_MIN_Distance(ALGraph G, int u);

void DFSTraverse(ALGraph G);
void DFS_1(ALGraph G, int i);
void DFS_2(MGraph G, int i);

//WD
bool isTree(ALGraph G);
void DFS_isTree(ALGraph G,int i,int &vexNum,int &arcNum,int visited[]);