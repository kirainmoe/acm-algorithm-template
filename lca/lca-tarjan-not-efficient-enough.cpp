#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5 * 5 + 10;

struct Edge {
  int last, next;
};
Edge e[MAXN << 1], query[MAXN << 1];

int n, m, s;
int cnt = 0, qcnt = 0;
int depth[MAXN];
int ans[MAXN];
int p[MAXN];
int G[MAXN], Q[MAXN];
bool vis[MAXN];

int find(int x)
{
  return x == p[x] ? x : p[x] = find(p[x]);
}

void addEdge(int u, int v)
{
  e[++cnt].next = v;
  e[cnt].last = G[u];
  G[u] = cnt;
}

void addQuery(int a, int b)
{
  query[++qcnt].next = b;
  query[qcnt].last = Q[a];
  Q[a] = qcnt;
}

void tarjan(int root, int dep)
{
  depth[root] = dep;
  for (int i = G[root]; i; i = e[i].last)
  {
    int son = e[i].next;
    if (!depth[son]) {
      tarjan(son, dep + 1);
      p[son] = root;
      vis[son] = 1;
    }
  }
  for (int i = Q[root]; i; i = query[i].last)
  {
    int cur = query[i].next;
    if (vis[cur]) {
      ans[i] = find(cur);
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    addQuery(a, b);
    addQuery(b, a);
  }
  
  for (int i = 0; i <= n; i++)
    p[i] = i;
    
  tarjan(s, 1);

  for (int i = 0; i < m; i++)
  {
    if (ans[i * 2 - 1]) {
      printf("%d\n", ans[i * 2 - 1]);
    } else if (ans[i * 2]) {
      printf("%d\n", ans[i * 2]);
    } else {
      m++;
    }
  }

  return 0;
}
