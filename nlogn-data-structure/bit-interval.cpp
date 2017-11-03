#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const int MAXN = 500050;

/**
* 支持区间修改的树状数组 (1)
* 这个版本相对完整，还有另一个效率比较高的版本，不把原数据扔进 BIT 里 
* @date 2017/11/3 11:14
*/
struct IntervalBIT {
    int n;
    
    LL a[MAXN], c[MAXN];    // c[] 是 a[] 的差分数组 
    
    // 初始化 
    void init(int t) {
        n = t;
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
    }
    
    // 树状数组 lowbit() 函数 
    int lowbit(int x)
    {
        return x & (-x);
    }
    
    /**
    * 修改数组 
    * @param long long* arr 要修改的数组 
    * @param int pos 修改的位置
    * @param long long addVal 修改的值 
    */ 
    void add(LL* arr, int pos, LL addVal) {
        while (pos <= n)
        {
            arr[pos] += addVal;
            pos += lowbit(pos);
        }
    }
    
    /**
    * 对某一数组进行求和操作 
    * @param long long* arr 要求和的数组 
    * @param int pos 前缀和的终点
    * @return long long 返回数组 arr 区间求和 [1, pos] 的结果 
    */ 
    LL sum(LL* arr, int pos) {
      LL res = 0;
      while (pos > 0)
      {
          res += arr[pos];
          pos -= lowbit(pos);
      }
      return res;
    }
    
    /**
    * 对两个数组进行差分及求和 
    * @param int pos 位置 
    * @return long long  
    */
    LL sigma(int pos) {
        LL sum1 = pos * sum(a, pos),
           sum2 = sum(c, pos);
        return sum1 - sum2;
    }
    
    /**
    * 区间查询 
    * @param int x 下界 
    * @param int y 上界
    * @return long long 返回查询的结果 
    */
    LL query(int x, int y) {
        return sigma(y) - sigma(x - 1);
    }
};

/*
食用方法：
(1)单点修改：tree.add(tree.a, pos, data[pos] - data[pos-1], tree.add(tree.c, pos, (i-1)*(data[i] - data[i-1]);
(2)区间修改[x, y] + k：
    tree.add(tree.a, x, k), tree.add(tree.a, y+1, -k);
    tree.add(tree.c, x, (x-1) * k), tree.add(tree.c, y+1, -y*k);
(3)区间查询[x, y]: tree.query(x, y);
(4)单点查询 x: tree.query(x, x);
*/ 

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
        tree.add(tree.a, i, data[i] - data[i-1]);
        tree.add(tree.c, i, (i - 1) * (data[i] - data[i-1]));
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, cmds;
        LL val;
        
        scanf("%d", &cmds);
        if (cmds == 1) {
            scanf("%d%d%lld", &x, &y, &val);
            tree.add(tree.a, x, val);
            tree.add(tree.a, y + 1, -val);
            tree.add(tree.c, x, (x - 1) * val);
            tree.add(tree.c, y + 1, -(y * val));
        } else {
            scanf("%d", &x);
            LL ans = tree.query(x, x);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
