#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const int MAXN = 100010;

/**
 * 线段树模板 （单点修改，区间修改，区间求和）
 * @Copyright(c) 2017 kirainmoe (https://github.com/kirainmoe/)
 */
struct SegTree {
  // 我！再！说！一！遍！ 线段树数组要开 4 倍！4 倍！4 倍！
  LL sum[MAXN << 2];       // 求和数组
  LL lazy[MAXN << 2];      // lazyTag 延迟标记

  /**
   * 初始化线段树
   * @return void
   */
  void init() {
    for (int i = 0; i < MAXN; i++) {
      sum[i] = 0, lazy[i] = 0;
    }
  }

  /**
   * 将信息从子节点上推到根节点
   * @param int root 根节点
   * @return void
   */
  void pushUp(int root) {
    sum[root] = sum[root * 2] + sum[root * 2 + 1];
  }

  /**
   * 将 lazyTag 下推
   * @param int root 根节点
   * @param int length 区间长度
   * @return void
   */
  void pushDown(int root, int length) {
    if (lazy[root]) {
      sum[root * 2] += lazy[root] * (length - (length / 2));
      sum[root * 2 + 1] += lazy[root] * (length / 2);
      lazy[root * 2] += lazy[root];
      lazy[root * 2 + 1] += lazy[root];
      lazy[root] = 0;
    }
  }

  /**
   * 建立一棵线段树
   * @param int root 根节点标号
   * @param int left 起点
   * @param int right 终点
   * @return void
   */
  void build(int root, int left, int right) {
    if (left == right) {
      scanf("%lld", &sum[root]);
      return;
    }

    int mid = (left + right) >> 1;
    build(root * 2, left, mid);
    build(root * 2 + 1, mid + 1, right);
    pushUp(root);
  }

  /**
   * 线段树区间修改
   * @param int root 根节点
   * @param int left 起点
   * @param int right 终点
   * @param int ufrom 待修改区间起点
   * @param int uto 待修改区间终点
   * @param int addVal 增加的值
   * @return void
   */
  void intervalUpdate(int root, int left, int right, int ufrom, int uto, int addVal) {
    if (ufrom <= left && right <= uto) {
      sum[root] += addVal * (right - left + 1);
      lazy[root] += addVal;
      return;
    }

    pushDown(root, right - left + 1);

    int mid = (left + right) >> 1;
    if (ufrom <= mid) {
      intervalUpdate(root * 2, left, mid, ufrom, uto, addVal);
    }
    if (mid < uto) {
      intervalUpdate(root * 2 + 1, mid + 1, right, ufrom, uto, addVal);
    }

    pushUp(root);
  }

  /**
   * 线段树单点修改
   * @param int root 根节点
   * @param int left 起点
   * @param int right 终点
   * @param int pos 修改的位置
   * @param int addVal 增加的值
   */
  void singleUpdate(int root, int left, int right, int pos, int addVal) {
    if (left == right) {
      sum[root] += addVal;
      return;
    }

    int mid = (left + right) >> 1;
    if (pos <= mid) {
      singleUpdate(root * 2, left, mid, pos, addVal);
    } else {
      singleUpdate(root * 2 + 1, mid + 1, right, pos, addVal);
    }

    pushUp(root);
  }

  /**
   * 线段树区间查询
   * @param int root 根节点
   * @param int left 起点
   * @param int right 终点
   * @param int qfrom 查询起点
   * @param int qto 查询终点
   */
  LL query(int root, int left, int right, int qfrom, int qto) {
    if (qfrom <= left && right <= qto) {
      return sum[root];
    }
    if (lazy[root]) {
      pushDown(root, right - left + 1);
    }

    int mid = (left + right) >> 1;
    LL ans = 0;
    if (qfrom <= mid) {
      ans += query(root * 2, left, mid, qfrom, qto);
    }
    if (mid < qto) {
      ans += query(root * 2 + 1, mid + 1, right, qfrom, qto);
    }

    return ans;
  }
};

SegTree tree;
int n, m;

int main()
{
  scanf("%d%d", &n, &m);

  tree.init();
  tree.build(1, 1, n);

  for (int i = 0; i < m; i++)
  {
    int cmd, x, y, k;
    scanf("%d", &cmd);
    // 给区间 [x, y] 加上 k
    if (cmd == 1) {
      scanf("%d%d%d", &x, &y, &k);
      tree.intervalUpdate(1, 1, n, x, y, k);
    }
    // 查询区间 [x, y]
    if (cmd == 2) {
      scanf("%d%d", &x, &y);
      LL ans = tree.query(1, 1, n, x, y);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
