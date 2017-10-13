/**
* HDU1874 SSSP dijkstra with priority_queue solution
* Time: 15ms
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 205;
const int MAXM = 1010;
const int INF = 1e9 + 7;

struct Edge {
  int v, w;
  // constructor
  Edge(int tv, int tw)
  {
    v = tv, w = tw;
  }
};
int n, m;
int dist[MAXN];
vector<Edge> e[MAXN];

void init()
{
  for (int i = 0; i < MAXN; i++)
  {
    e[i].clear();
    dist[i] = INF;
  }
}

int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    init();
    // building graph
    for (int i = 0; i < m; i++) 
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      
      e[u].push_back(Edge(v, w));
      e[v].push_back(Edge(u, w));
    }
    int start, end;
    scanf("%d%d", &start, &end);
    
    // dijkstra + priority_queue optimized
    priority_queue<pair<int, int> > Q;      // first int is point index, second int is priority
    dist[start] = 0;
    Q.push(make_pair(start, 0));
    
    while (!Q.empty())
    {
      // fetch the first element of queue
      int cur = Q.top().first;
      Q.pop();
      
      // foreach the edges of point `cur`
      for (unsigned int i = 0; i < e[cur].size(); i++)
      {
        int v = e[cur][i].v, w = e[cur][i].w;
        if (dist[v] > dist[cur] + w) {
          dist[v] = dist[cur] + w;
          Q.push(make_pair(v, -dist[v]));     // be careful that v's priority is negative dist[v]
        }
      } // for i = 0 -> e[cur].size()
    }
    
    if (dist[end] == INF) {
      printf("-1\n");
    } else {
      printf("%d\n", dist[end]);
    }
  }
  
  return 0;
}
