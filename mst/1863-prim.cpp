 #include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 105;

struct Edge {
  int v, w;
  Edge(int tv, int tw)
  {
    v = tv, w = tw;
  }
};
int n, m;
int ans = 0;
int dist[MAXN];
bool vis[MAXN];
vector<Edge> e[MAXN];

void init()
{
  ans = 0;          // 初始化答案 
  
  memset(vis, 0, sizeof vis);
  
  for (int i = 0; i < MAXN; i++)
  {
    dist[i] = INF;
    e[i].clear();
  }
}

int main()
{
  // n 为点数量， m 为边数量 
  while (scanf("%d%d", &m, &n) != EOF && m != 0)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    
    /* Prim */
    bool flag = true;               // 如果 flag = false，说明无法连通整张图 
    dist[1] = 0, vis[1] = 1;        // 因为题目的标号从 1 开始，所以把 1 作为起点 
    // 遍历起点的所有边，更新 dist[v] = w
    for (unsigned int i = 0; i < e[1].size(); i++)
    {
      int v = e[1][i].v, w = e[1][i].w;
      dist[v] = w;
    }
    /*
    注意这里的边界，i = 1(起点) -> n(最后一个点)，最后一个点是不访问的
    因为如果访问到最后一个点时图已经连通，vis[x] = 1 一定成立，那么 flag 会被重置为 false 
    */
    for (int i = 1; i < n; i++)
    {
      int cur, w = INF;         // cur 是当前能找到的下一个代价最小的点，w 是最小代价 
      // 和 dijkstra 有些异曲同工之妙 
      for (int j = 1; j <= n; j++)
      {
        if (!vis[j] && dist[j] < w) {
          cur = j, w = dist[j];
        }
      }
      // 如果找不到符合条件的点，说明图无法连通 
      if (w == INF) {
        flag = false;
        break;
      }
      
      ans += w;
      vis[cur] = 1;     // 标记下一个点已访问
      // 对于选定的点，遍历它的所有出边，进行松弛操作 
      for (unsigned i = 0; i < e[cur].size(); i++)
      {
        int v = e[cur][i].v, w = e[cur][i].w;
        if (!vis[v] && dist[v] > w) {
          dist[v] = w;
        }
      }
    } /* end prim */
    
    if (!flag) {
      printf("?\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}

