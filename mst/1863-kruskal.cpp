/**
* HDU1233 最小生成树模板题 Kruskal 实现 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
struct Edge {
  int u, v, w;
};
int n, m;
int ans = 0, times = 0;
int p[MAXN];
Edge edges[MAXN * MAXN];

bool cmp(const Edge a, const Edge b)
{
  return a.w < b.w;
}

void init()
{
  ans = 0;          // 初始化答案 
  times = 0;        // 初始化合并次数 
  
  memset(edges, 0, sizeof edges);
  
  // 初始化并查集 
  for (int i = 0; i < MAXN; i++)
  {
    p[i] = i;
  }
}

/* 并查集：查找 */
int find(int x)
{
  return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
  // n 为点数量， m 为边数量 
  while (scanf("%d%d", &m, &n) != EOF && m != 0)
  {
    init();
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    // 给边按照权值从小到大排序 
    sort(edges, edges + m, cmp);
    
    for (int i = 0; i < m; i++)
    {
      int x = edges[i].u, y = edges[i].v;
      // 并查集的合并操作
      // 查询当前边起点和终点所在集合 
      int px = find(x),
        py = find(y);
      
      if (px == py) {
        continue;           // 如果 px 和 py 在一个集合中，则不做任何操作 
      } else {
        p[px] = py;         // 合并 
        ans += edges[i].w;  // 更新答案 
        times++;            // 合并次数+1 
      }
    }
    // 没有找到最小生成树 
    if (times != n-1) {
      printf("?\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
