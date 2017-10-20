/* ±¶ÔöÇó LCA: Loweest Common Ancestor */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5 * 1e5 + 10;

vector<int> tree[MAXN];
int nodes, queries, root;
int ancestor[MAXN][25];
int depth[MAXN];
bool vis[MAXN];

void dfs(int s, int dep, int father)
{
  depth[s] = dep;
  vis[s] = 1;
  ancestor[s][0] = father;
  
  for (int i = 1; (1 << i) <= dep; i++)
  {
    ancestor[s][i] = ancestor[ancestor[s][i-1]][i-1];
  }
  
  for (unsigned int i = 0; i < tree[s].size(); i++)
  {
    int cur = tree[s][i];
    if (!vis[cur]) {
      dfs(cur, dep + 1, s);
    }
  }
}

int lca(int x, int y)
{
  if (depth[x] < depth[y]) {
    swap(x, y);
  }
  
  for (int i = 20; i >= 0; i--)
  {
    if (depth[ancestor[x][i]] >= depth[y]) {
      x = ancestor[x][i];
    }
  }
  
  if (x == y) {
    return x;
  }
  
  for (int i = 20; i >= 0; i--)
  {
    if (ancestor[x][i] != ancestor[y][i]) {
      x = ancestor[x][i];
      y = ancestor[y][i];
    }
  }
  
  return ancestor[x][0];
}

int main()
{
  scanf("%d%d%d", &nodes, &queries, &root);
  for (int i = 0; i < nodes - 1; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  
  ancestor[root][0] = root;
  dfs(root, 1, root);
  
  for (int i = 0; i < queries; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
  
  return 0;
}
