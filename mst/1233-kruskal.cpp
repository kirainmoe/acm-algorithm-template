#include <bits/stdc++.h> 
using namespace std;

struct edge {
  int u, v, w;
};
const int maxn = 10000;

int vill;
int ans = 0;
int p[maxn];
edge e[maxn];


void init()
{
  ans = 0;
  for (int i = 0; i < maxn; i++) 
  {
    e[i].u = 0;
    e[i].v = 0;
    e[i].w = 1e9;
    p[i] = i;
  }
}

bool cmp(const edge a, const edge b)
{
  return a.w < b.w;
}

int find(int x)
{
  return p[x] == x ? p[x] : p[x] = find(p[x]);
}

int main()
{
  while (scanf("%d", &vill) != EOF)
  {
    if (vill == 0) {
      break;
    }
    
    init();
    int edgeCount = vill * (vill - 1) / 2;
    
    for (int i = 0; i < edgeCount; i++)
    {
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    
    sort(e, e+edgeCount, cmp);
    
    for (int n = 0; n < edgeCount; n++)
    {
      int px = find(e[n].u),
          py = find(e[n].v);
      if (px != py) {
        p[px] = py;
        ans += e[n].w;
      }
    }
    
    printf("%d\n", ans);
  } // while
  
  return 0;
}

