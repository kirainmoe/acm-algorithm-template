#include <cstdio>
#include <cstring>

const int MAXN = 1e3 + 10;
int n[MAXN];
char target[MAXN], pattern[MAXN];

void init()
{
  memset(target, 0, sizeof target);
  memset(pattern, 0, sizeof pattern);
  memset(n, 0, sizeof n);
}

void calcNext()
{
  n[0] = -1;
  int i = 0, k = -1, len = strlen(pattern) - 1;
  while (i < len)
  {
    if (k == -1 || pattern[i] == pattern[k]) {
      n[++i] = ++k;
      if (pattern[i] == pattern[k]) {
        n[i] = n[k];
      }
    } else {
      k = n[k];
    }
  }
}

int KMP()
{
  int ans = 0, i = 0, j = 0;
  int tlen = strlen(target), plen = strlen(pattern);
  
  while (i < tlen)
  {
    if (j == -1 || target[i] == pattern[j]) {
      i++, j++;
    } else {
      j = n[j];
    }
    if (j == plen) {
      j = 0;
      ans++;
    }    
  }
  return ans;
}

int main()
{
  while (~scanf("%s", target))
  {
    if (target[0] == '#')
      break;
    scanf("%s", pattern);
    calcNext();
    int ans = KMP();
    printf("%d\n", ans);
    init();
  }
  return 0;
}
