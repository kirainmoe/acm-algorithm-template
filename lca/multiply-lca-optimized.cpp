/**
* 利用倍增思想求 LCA(Lowest Common Ancestor, 最近公共祖先) 
* https://www.luogu.org/problem/show?pid=3379
*/ 

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 * 5 + 10;
const int MAXLOG = 19;            // 数据范围 50w, 2^19 即可 

// 手打邻接表，因为用 vector 常数太大会超时 qwq 
struct Edge {
  int last;     // last 表示从 u 点出发的上一条边
  int next;     // next 表示 u 点连接的下一个点 v 
};
Edge e[MAXN << 1];  // 边是双向的，所以数组要开大一倍 

int n, m, s, cnt = 0;
int depth[MAXN];                  // depth[i] 表示节点 i 的深度 
int G[MAXN];                      // G[i] 表示从 i 出发的最后一条边的 index 
int ancestor[MAXN][MAXLOG + 5];   // ancestor[i][j] 表示第 i 个点的第 2^j 个祖先的标号 
bool vis[MAXN];                   // DFS 数组 

/**
 * 手撸邻接表加边操作 
 * @param int u 起点 
 * @param int v 终点 
 */ 
void addEdge(int u, int v)
{
  e[++cnt].next = v;
  e[cnt].last = G[u];
  G[u] = cnt;
}

/**
 * DFS 预处理，计算每一个点的 ancestor[] 数组，填充 depth[] 数组 
 * @param int root   起点
 * @param int dep    当前节点深度
 * @param int father 当前节点父亲 
 */ 
void dfs(int root, int dep, int father)
{
  ancestor[root][0] = father;       // i 节点的第 2^0 个祖先即为其父亲 
  depth[root] = dep;
  vis[root] = 1;
  /* i 节点的第 2^j 个祖先 = **i 节点的第 2^(j-1) 个祖先** 的第 2^(j-1) 个祖先 */ 
  for (int i = 1; (1 << i) <= dep; i++)
  {
    ancestor[root][i] = ancestor[ancestor[root][i-1]][i-1];
  }
  
  // 对于从节点 root 出发的每条边，递归填充 depth 数组、预处理 ancestor 
  for (int i = G[root]; i; i = e[i].last)
  {
    int next = e[i].next;
    if (!vis[next]) {
      dfs(next, dep + 1, root);
    }
  }
}

/**
 * 求解 LCA 
 * @param int x
 * @param int y
 */
int lca(int x, int y)
{
  // 我们约定 x 是较深的那一个节点，如果 x 的深度小于 y 就交换 x, y 
  if (depth[x] < depth[y]) {
    swap(x, y);
  }
  
  // 接下来要把 x 节点跳到和 y 节点同一个高度的地方 
  // 用 delta 表示 x 与 y 的深度差，从 0 循环到 MAXLOG 
  int delta = depth[x] - depth[y];
  for (int i = 0; i <= MAXLOG; i++)
  {
    if (delta & (1 << i)) {
      x = ancestor[x][i];
    }
  }
  
  /*
  // 下面的代码也是可以的，而且会更好理解一些 
  for (int i = MAXLOG; i >= 0; i--)
  {
    if (depth[y] <= depth[ancestor[x][i]]) {    // 注意这里的条件是 深度小的 <= 深度大的的祖先的深度 
      x = ancestor[x][i];
    }
  }
  */  
  
  // 如果已经在同一个高度而且 x, y 相等，说明 y 是 x 的祖先，返回 y 
  if (x == y) {
    return y;
  }
  // 否则，就两个一起往上跳，但是这时候应该从 MAXLOG 跳回来到 0 
  for (int i = MAXLOG; i >= 0; i--)
  {
    // x 的第 2^i 个祖先与 y 的第 2^i 个祖先不同时，就让 x,y 分别等于其祖先，接着往上跳 
    if (ancestor[x][i] != ancestor[y][i]) {
      x = ancestor[x][i], y = ancestor[y][i];
    }
  }
  // 最后，返回其公共祖先 ancestor[x][0]
  return ancestor[x][0];
}

int main()
{
  scanf("%d%d%d", &n ,&m, &s);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  
  dfs(s, 1, s);             // 深度应该从 1 开始~ 
  
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
  
  return 0;
}
