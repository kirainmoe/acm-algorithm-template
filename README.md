# Algorithm Template of OI

Some widely used algorithm templates in OI competition. Still collecting.....

> 一些 OI 算法竞赛里常用的算法模板，整理这个仓库是受到 [另一名本校选手](https://gitee.com/pantw/OI_templates) 的启发。 11 月前将不断更新中……

目录 / Table of Contents
=======================

  * [写在前面](#写在前面)
  * [单源最短路](#single-source-shortest-path)
    * [传统 Dijkstra 解法](#traditional-dijkstra)
    * [使用优先队列优化的 Dijkstra](#priority-queue-optimized-dijkstra)
    * [SPFA](#spfa)
  * [多源最短路](#multi-source-shortest-path)
    * [Floyd-Warshall](#floyd-warshall)
    * [调用 n 次 SPFA/Dijkstra](#spfa-for-mssp)
  * [最小生成树](#mst)
    * [Kruskal](#kruskal)
    * [Prim](#prim)
  * [数论专题](#mathematics)
    * [最小公约数和最大公倍数](#gcd-lcm)
    * [素数筛](#prime-sieve)
  * [字符串匹配](#string-matching)
    * [KMP 算法](#kmp-algorithm)
  * [最近公共祖先 LCA](#lowest-common-ancestor)
    * [在线：倍增实现](#multiply-lca)
    * [邻接表优化：倍增实现](#multiply-lca-optimized)
    * [离线：Tarjan](#tarjan)
  * [网络流](#network-flow)
    * [最大流：Edmonds Karp 算法](#edmonds-karp)
  * [nlogn 数据结构](#nlogn-data-structure)
    * [线段树（单点/区间修改，区间求和）](#segmeng-tree-sum)
    * [树状数组 (单点修改，区间求和)](#single-bit)
    * [树状数组 (区间修改，区间求和)](#interval-bit)

# 写在前面

1. 几乎每个模板的记录方式都有一道背景问题（一般都是 HDU 的中文模板题）来帮助理解。
2. 注释什么的会看心情写，以帮助自己理解为原则，有可能某些部分是错误的，所以各位乐意或者觉得有点帮助的话就稍微看看，其他的就拉倒。
3. 欢迎纠正错误 / 增添其他的模板，或者补充其他的写法。
4. 我的代码风格比较奇怪（<s>因为我有强迫症 + 我觉得还是可以读的</s>），所以大家凑合着看吧。

# Single Source Shortest Path

位于 ```/single-source-shortest-path``` 文件夹。

> 问题背景是 HDU1874: http://acm.hdu.edu.cn/showproblem.php?pid=1874

### Traditional Dijkstra
  
O(n^2), [dijkstra-traditional.cpp](single-source-shortest-path/dijkstra-traditional.cpp), 数据大的话基本不能用，实测 HDU1874 在 15ms 左右。

### Priority Queue Optimized Dijkstra

O(mlogn), [dijkstra-priority-queue.cpp](single-source-shortest-path/dijkstra-priority-queue.cpp)，HDU1874 在 15ms 左右，但是更多的情况下应该会比上面那个快。

### SPFA

O(me), [spfa.cpp](single-source-shortest-path/spfa.cpp), 好写极了，也比较常用，这题跑出来是 0ms...

# Multi Source Shortest Path

位于 ```/multi-source-shortest-path``` 文件夹。

> 问题背景是 HDU2066:  http://acm.hdu.edu.cn/showproblem.php?pid=2066

### Floyd Warshall

经典的 O(n^3) Floyd-Warshall + 剪枝的算法，用邻接矩阵存图。嘛，效率不是很高，但是好写。

[2066-floyd.cpp](multi-source-shortest-path/2066-floyd.cpp)

### SPFA for MSSP

通过调用 n 次 SPFA 来求 n 个起点的最短路，复杂度是 O(n*me)，看起来效率是比 Floyd 高了不少的样子。也可以用 n 次 Dijkstra 来做，复杂度相应的应该是 (n*mlogn). 这里只提供 SPFA 的做法。

[2066-spfa.cpp](multi-source-shortest-path/2066-spfa.cpp)

# MST

位于 ```/mst``` 文件夹。

### Kruskal

> 问题背景1 HDU1233: http://acm.hdu.edu.cn/showproblem.php?pid=1233

[1233-kruskal.cpp](mst/1233-kruskal.cpp)

> 问题背景2 HDU1863: http://acm.hdu.edu.cn/showproblem.php?pid=1863

[1863-kruskal.cpp](mst/1863-kruskal.cpp)

### Prim

> 问题背景：HDU1863: http://acm.hdu.edu.cn/showproblem.php?pid=1863

[1863-prim.cpp](mst/1863-prim.cpp)

# Mathematics

### GCD & LCM

求最小公约数和最大公倍数，没有背景题。

[gcd-lcm.cpp](mathematics/gcd-lcm.cpp)

### Prime Sieve

素数筛，有线性筛和埃氏筛法两种算法。

[prime-sieve.cpp](mathematics/prime-sieve.cpp)

# String Matching

### KMP Algorithm

著名的 KMP 算法。 可以在 O(n+m) 的时间复杂度里匹配字符串。

> 问题背景：HDU2087: http://acm.hdu.edu.cn/showproblem.php?pid=2087

> 我在学 KMP 的时候专门写了一篇文章帮助理解：https://kirainmoe.com/blog/post/kmp-algorithm-for-matching-string/

[2087.cpp](kmp/2087.cpp)

[辅助 next 数组理解和最原始的 KMP 算法模板](kmp/kmp.cpp)

# Lowest Common Ancestor

树的最近公共祖先算法。 主要有倍增，RMQ 和 Tarjan 三种实现。

### Multiply LCA

倍增求 LCA 的标准模板。使用 vector 实现，好理解也好写。

[multiply-lca.cpp](lca/multiply-lca.cpp)

### Multiply LCA Optimized

优化过的倍增求 LCA 模板。这回手撸链表，常数比 vector 版本的小了不少。

> 问题背景：luogu3379: https://www.luogu.org/problem/show?pid=3379

> 别问我为什么是 luogu, 最近开会 HDU 上不去 QAQ

[multiply-lca-optimized.cpp](lca/multiply-lca-optimized.cpp)

### Tarjan

Tarjan 是一种求 LCA 的离线算法。这里只有一份效率不是很高的 Tarjan 模板，虽然似乎很好理解，然而我就是写不对 qwq

[lca-tarjan-not-efficient-enough.cpp](lca/lca-tarjan-not-efficient-enough.cpp)

# Network Flow

网络流相关算法。预计收集完整之后有最大流、最小费用最大流、最大流最小割……等等。

## 最大流
### Edmonds Karp

求解最大流的著名算法： Edmonds Karp 算法。对于这个算法的话我强烈推荐这篇博文：http://www.cnblogs.com/ZJUT-jiangnan/p/3632525.html ，文章里的概念、流程和代码等等都非常清楚，值得细读和借鉴。事实上这里的代码也正是参考了这篇文章当中给出的。

> 问题背景： HDU3549: http://acm.hdu.edu.cn/showproblem.php?pid=3549

[3549-maxflow.cpp](network-flow/3549-maxflow.cpp)

该算法的模板 + 注释（推荐，虽然不具有广泛适用性，但这个模板好理解）：[edmonds-karp-maxflow.cpp](network-flow/edmonds-karp-maxflow.cpp)

刘汝佳的 《算法竞赛入门经典（第二版）》 P368-369 中也给出了这个算法的实现代码，但是较难理解，这里只用于对比：[edmonds-karp-maxflow-rjliu.cpp](network-flow/edmonds-karp-maxflow-rjliu.cpp)

# nlogn 数据结构

这里是一些 nlogn 级别的数据结构，有大家<s>熟悉</s>的线段树，树状数组……等等。

## 线段树

### Segment Tree Sum

> 问题背景：https://www.luogu.org/problemnew/show?pid=3372

本来 单点修改区间求和 跟 区间修改区间求和 应该是分开两种的，这里把它压到一份代码里了。背景题是区间修改的模板题，如果你有兴趣的话，HDU 有一道单点修改区间求和的模板题（HDU1166）：http://acm.hdu.edu.cn/showproblem.php?pid=1166

[segment-tree-sum.cpp](nlogn-data-structure/segment-tree-sum.cpp)


## 树状数组

### Single BIT

> 问题背景：http://acm.hdu.edu.cn/showproblem.php?pid=1166

单点修改、区间查询，这个是最基础的树状数组模板= = [bit-1166.cpp](nlogn-data-structure/bit-1166.cpp)

是不是这一题很眼熟呢，没错这道题用线段树同样可做~

### Interval BIT

> 问题背景：https://www.luogu.org/problemnew/show/3368

树状数组的区间修改和区间求和~用到了一个很神奇的差分的思想。事实上用树状数组的区间求和和区间查询版，是可以把上面那道区间修改线段树切掉的（

有两个版本，第一个版本是完整的，把所有数据都交给 BIT 处理，代码量有点大，细节也有点多。[bit-interval.cpp](nlogn-data-structure/bit-interval.cpp)

另一个版本是只用树状数组来维护差分序列，然后查询的时候加上原数据，避免了把原数据全都丢进去的过程。这个效率更高，但是相对来说如果要做区间查询那就麻烦一些~ [bit-interval-2.cpp](nlogn-data-structure/bit-interval-2.cpp)

# 其他 / Others

This repository is MIT licensed.