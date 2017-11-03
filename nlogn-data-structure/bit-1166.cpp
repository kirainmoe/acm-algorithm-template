#include <bits/stdc++.h>

const int MAXN = 50005;
int n;
int c[MAXN];

int lowbit(int x)
{
  return x & (-x);
}

void add(int i, int value)
{
  while (i <= n)
  {
    c[i] += value;
    i += lowbit(i);
  }
}

int sum(int x)
{
  int res = 0;
  while (x > 0)
  {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}

int main()
{
  int t;
  scanf("%d", &t);
  
  for (int i = t; i > 0; i--)
  {
    printf("Case %d:\n", t - i + 1);
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    
    for (int j = 1; j <= n; j++)
    {
      int x;
      scanf("%d", &x);
      add(j, x);
    }
    
    char str[10];
    int x, y;
    while (scanf("%s", str) != EOF && str[0] != 'E')
    {
      scanf("%d%d", &x, &y);
      
      if (str[0] == 'Q') {
        int res = sum(y) - sum(x-1);
        printf("%d\n", res);
      }
      
      if (str[0] == 'A') {
        add(x, y);
      }
      
      if (str[0] == 'S') {
        add(x, -y);
      }
    }
    
  }
  
  return 0;
}
