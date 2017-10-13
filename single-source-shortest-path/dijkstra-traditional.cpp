/**
* HDU1874 SSSP: traditional dijkstra solution
* Time: 15ms
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 205;
const int MAXM = 1020;
const int INF = 1e9 + 7;
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
    e[i].clear();
    dist[i] = INF;
  }
  memset(vis, 0, sizeof vis);
}

int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    // initilaize
    init();
    // read-in edges
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v ,&w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    int start, end;
    scanf("%d%d", &start, &end);
    
    // traditional dijkstra
    dist[start] = 0;
    for (int i = 0; i < n; i++)
    {
      int cur, ref = INF;
      
      // 1 => find the point `cur` which has the smallest dist and hasn't been visited
      for (int j = 0; j < n; j++)
      {
        if (!vis[j] && dist[j] <= ref) {
          // update reference and current
          ref = dist[j];
          cur = j;
        }
      } // for j = 0 -> n
      
      // 2 => mark current point as visited
      vis[cur] = 1;
      
      // 3 => for E(cur, v) starting from cur
      // update dist[v] = min(dist[v], dist[cur] + w(x, y))
      for (unsigned int j = 0; j < e[cur].size(); j++)
      {
        int v = e[cur][j].v, w = e[cur][j].w;
        dist[v] = min(dist[v], dist[cur] + w);
      }
    }
    
    // cannot access end-point
    if (dist[end] == INF) {
      printf("-1\n");
    } else {
      printf("%d\n", dist[end]);
    }
  }
  
  return 0;
}
