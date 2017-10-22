#include <cstdio> 
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
int t, n, m;
int map[100][100];
int pre[100];
bool vis[100];

void updateResidualNetwork(int t, int flow)
{
  while (pre[t] != -1)
  {
    map[pre[t]][t] -= flow;
    map[t][pre[t]] += flow;
    t = pre[t];
  }
}

int findPath(int s, int t)
{
  memset(vis, 0, sizeof vis);
  memset(pre, -1, sizeof pre);
  queue<int> Q;
  int minflow = INF;
  vis[s] = 1;
  Q.push(s);
  
  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    
    if (cur == t) {
      break;
    }
    
    for (int i = 1; i <= n; i++)
    {
      if (!vis[i] && map[cur][i]) {
        Q.push(i);
        vis[i] = 1;
        minflow = min(minflow, map[cur][i]);
        pre[i] = cur;
      }
    }
  }
  
  if (pre[t] == -1) {
    return 0;
  } else {
    return minflow;
  }
}

int edmondsKarp(int s, int t)
{
  int newFlow = 0, maxFlow = 0;
  do {
    newFlow = findPath(s, t);
    updateResidualNetwork(t, newFlow);
    maxFlow += newFlow;
  } while (newFlow != 0);
  return maxFlow;
}

int main()
{
  scanf("%d", &t);
  int cases = 0;
  while (t--)
  {
    cases++;
    memset(map, 0, sizeof map);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
      int u, v, cap;
      scanf("%d%d%d", &u, &v, &cap);
      map[u][v] = cap;
    }
    int ans = edmondsKarp(1, n);
    printf("Case %d: %d\n", cases, ans);
  }
  return 0;
}
