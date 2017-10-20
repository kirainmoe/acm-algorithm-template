# Algorithm Template of OI

Some widely used algorithm templates in OI competition.

Inspired from [Gitee: pantw/oi_templates](https://gitee.com/pantw/OI_templates).

Still collecting.....

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
  * [字符串匹配](#string-matching)
    * [KMP 算法](#kmp-algorithm)
  * [最近公共祖先 LCA](#lowest-common-ancestor)
    * [在线：倍增实现](#multiply-lca)
    * [邻接表优化：倍增实现](#multiply-lca-optimized)

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

# 其他 / Others

This repository is MIT licensed.