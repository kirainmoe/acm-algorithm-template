#include <cstdio> 
#include <cstring>
const int MAXN = 233;
int next[MAXN];
char target[MAXN], pattern[MAXN];

void calcNextArr()
{
  next[0] = -1;
  int j = 0, k = -1, len = strlen(pattern) - 1;
  while (j < len)
  {
    if (k == -1 || pattern[j] == pattern[k]) {
      next[++j] = ++k;
      // 如果要做时间复杂度优化，路径压缩：
      if (pattern[j] == pattern[k]) {
        next[j] = next[k];
      }
    } else {
      k = next[k];
    }
  }
  
  printf("next[] array calculated:\n");
  for (int i = 0; i < strlen(pattern); i++)
    printf("%d ", next[i]);
  printf("\n");
}

int KMP()
{
  int i = 0, j = 0;
  int tlen = strlen(target), plen = strlen(pattern);
  while (i < tlen && j < plen)
  {
    if (j == -1 || target[i] == pattern[j]) {
      i++, j++;
    } else {
      j = next[j];
    }
  }
  
  if (j == plen) {
    return i - j;
  } else {
    return -1;
  }
}

int main()
{
  memset(target, 0, sizeof target);
  memset(pattern, 0, sizeof pattern);
  memset(next, 0, sizeof next);
  
  printf("Target string:");
  scanf("%s", target);
  printf("Pattern string:");
  scanf("%s", pattern);
  
  calcNextArr();
  int pos = KMP();
  
  if (pos == -1) {
    printf("No match.\n");
  } else {
    printf("Matched at %d\n", pos);
  }
  
  return 0;
}
