const int MAXN = 2333;
bool isPrime[MAXN];
int prime[MAXN];
int cnt = 0;

// 线性筛法
void sieve(int limit)
{
  /* 初始化，首先标记范围内所有的数都是素数 */
  for (int i = 0; i <= limit; i++)
  {
    isPrime[i] = true;
  }

  /* 0 和 1 不是素数，过滤之 */
  isPrime[0] = isPrime[1] = false;

  /* 接下来，从 2 开始遍历每一个数 */
  for (int i = 2; i <= limit; i++)
  {
    if (isPrime[i]) {
      prime[cnt++] = i;   // 加入素数表
    }

    for (int j = 0; j < cnt && i * prime[j] <= lim; j++)
    {
      isPrime[i * prime[j]] = false;
      if (i % prime[j] == 0) {
        break;
      }
    } // for j = 0 -> cnt
  } // for i = 2 => limit
} // void sieve()

// 埃氏筛法
void eth_sieve(int limit)
{
  for (int i = 0; i <= limit; i++)
  {
    isPrime[i] = true;
  }
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= limit; i++)
  {
    if (isPrime[i]) {
      prime[cnt++] = i;
      for (int j = i; j <= limit; j += i)
      {
        isPrime[j] = false;
      } // for j = i => limit
    }
  } // for j = 2 => limit
} // void eth_sieve()