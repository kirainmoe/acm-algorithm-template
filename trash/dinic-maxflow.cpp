#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
  int cap, flow;
};
Node edge[233][233];

const int INF = 1e9 + 7;
int n, m;
int level[233];

bool buildStageNetwork()
{
  queue<int> Q;
  memset(level, 0, sizeof level);
  
  Q.push(1);
  level[1] = 1;
  
  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    
    for (int v = 1; v <= n; v++)
    {
      if (!level[v] && edge[u][v].cap > edge[u][v].flow) {
        level[v] = level[u] + 1£»
        Q.push(v);
      }
    } // v = 1 => n
  } // Q.empty()
}

int augmentFlow(int u, int cap)
{
  
}

int dinic()
{
  int maxFlow = 0, newFlow = 0;
  while (buildStageNetwork())
  {
    while (newFlow = augmentFlow()) 
    {
      maxFlow += newFlow;
    }
  }
  return maxFlow;
}

int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    memset(edge, 0, sizeof edge);
    for (int i = 0; i < m; i++)
    {
      int u, v, cap;
      scanf("%d%d%d", &u, &v, &cap);
      edge[u][v].cap += cap;
    }
    int ans = dinic();
    printf("%d\n", ans);
  }
}
