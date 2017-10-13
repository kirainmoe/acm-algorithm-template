/**
* HDU1874 SSSP SPFA solution
* Time: 0ms.... (?????)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 205;
const int MAXM = 1010;

struct Edge {
  int v, w;
  Edge(int tv, int tw)
  {
    v = tv, w = tw;
  }
};

int n, m;
int dist[MAXN];
bool vis[MAXN];
vector<Edge> e[MAXN];

void init()
{
  for (int i = 0; i < MAXN; i++)
  {
    dist[i] = INF;
    e[i].clear();
  }
  memset(vis, 0, sizeof vis);
}

int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    int start, end;
    scanf("%d%d", &start, &end);
    
    // SPFA
    queue<int> Q;
    Q.push(start);
    vis[start] = 1;
    dist[start] = 0;    // so important
    
    while (!Q.empty())
    {
      int cur = Q.front();
      Q.pop();
      vis[cur] = 0;
      
      for (unsigned int i = 0; i < e[cur].size(); i++)
      {
        int v = e[cur][i].v, w = e[cur][i].w;
        if (dist[v] > dist[cur] + w) {
          dist[v] = dist[cur] + w;
          Q.push(v);
          vis[v] = 1;
        }
      } // for i = 0 -> e[cur].size
    }
    
    if (dist[end] == INF) {
      printf("-1\n");
    } else {
      printf("%d\n", dist[end]);
    }
  }
  return 0;
}
