#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const int MAXN = 500050;

/**
* 支持区间修改的树状数组 (2)
* 这个版本不把原数据扔进 BIT 里，只用树状数组维护差分序列 
* 效率比较高也好写，但是相对的来说一些诸如区间查询的操作就略显复杂 
* 嘛，其实这个树状数组还是原来的树状数组，只是思维有点变化
* 查询的时候用原值加上这个差分值就可以了（大概这个意思） 
* @date 2017/11/3 11:22
*/
struct IntervalBIT {
    int n;
    LL a[MAXN];
    
    void init(int t) {
        n = t;
        memset(a, 0, sizeof a);
    }
    
    int lowbit(int x)
    {
        return x & (-x);
    }
    
    void add(int pos, LL addVal) {
        while (pos <= n)
        {
            a[pos] += addVal;
            pos += lowbit(pos);
        }
    }
    
    LL sum(int pos) {
      LL res = 0;
      while (pos > 0)
      {
          res += a[pos];
          pos -= lowbit(pos);
      }
      return res;
    }
};

IntervalBIT tree;
int n, m;
LL data[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    tree.init(n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &data[i]);
    }
    
    for (int i = 1; i <= m; i++)
    {
        int x, y, cmds;
        LL val;
        
        scanf("%d", &cmds);
        if (cmds == 1) {
            scanf("%d%d%lld", &x, &y, &val);
            // 因为 BIT 利用了前缀和的思想，所以直接建树维护差分序列即可 
            tree.add(x, val);
            tree.add(y + 1, -val);
        } else {
            scanf("%d", &x);
            // 单点查询的时候结果就是原数据+差分值 
            LL ans = data[x] + tree.sum(x);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
