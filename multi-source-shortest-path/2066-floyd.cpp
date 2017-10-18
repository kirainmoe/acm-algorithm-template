#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e3 + 10;

int t, s, d;
int n;
int ans = INF;
int dist[MAXN][MAXN];
int linked[MAXN];
int wish[MAXN];

void init()
{
  n = 0, ans = INF;
  memset(wish, -1, sizeof wish);
  memset(linked, -1, sizeof linked);
  
  for (int i = 0; i < MAXN; i++)
  {
    for (int j = 0; j < MAXN; j++)
    {
      dist[i][j] = (i == j ? 0 : INF);
    }
  }
}

int main()
{
  while (scanf("%d%d%d", &t, &s, &d) != EOF)
  {
    init();
    for (int i = 0; i < t; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      if (dist[u][v] > w || dist[v][u] > w) {
        dist[u][v] = dist[v][u] = w;
      }
      n = max(n, max(u, v));
    }
    
    for (int i = 0; i < s; i++)
    {
      scanf("%d", &linked[i]);
    }
    
    for (int i = 0; i < d; i++)
    {
      scanf("%d", &wish[i]);
    }
    
    // floyd
    for (int k = 0; k <= n; k++)
      for (int i = 0; i <= n; i++)
        if (dist[i][k] != INF) {          // ¶Ô floyd Ëã·¨¼ôÖ¦ 
          for (int j = 0; j <= n; j++)
            dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);          
        }

    for (int i = 0; i < s; i++)
    {
      int u = linked[i];
      for (int j = 0; j < d; j++)
      {
        int v = wish[j];
        ans = min(ans, dist[u][v]);
      }
    }
    
    printf("%d\n", ans);
  }
  return 0;
}
