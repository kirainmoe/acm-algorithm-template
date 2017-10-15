# Algorithm Template of OI

Some widely used algorithm templates in OI competition.

Inspired from [Gitee: pantw/oi_templates](https://gitee.com/pantw/OI_templates).

Still collecting.....

> 一些 OI 算法竞赛里常用的算法模板，整理这个仓库是受到 [另一名本校选手](https://gitee.com/pantw/OI_templates) 的启发。 11 月前将不断更新中……

目录 / Table of Contents
=======================

  * [写在前面](#_1)
  * [单源最短路](#single-source-shortest-path)
    * [传统 Dijkstra 解法](#traditional-dijkstra)
    * [使用优先队列优化的 Dijkstra](#priority-queue-optimized-dijkstra)
    * [SPFA](#spfa)
  * [最小生成树](#mst)
    * [Kruskal](#kruskal)
    * [Prim](#prim)
  * [数论专题](#mathematics)
    * [最小公约数和最大公倍数](#gcd-lcm)

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

# MST

位于 ```/mst``` 文件夹。

### Kruskal

> 问题背景1 HDU1233：http://acm.hdu.edu.cn/showproblem.php?pid=1233

[1233-kruskal.cpp](mst/1233-kruskal.cpp)

> 问题背景2 HDU1863：http://acm.hdu.edu.cn/showproblem.php?pid=1863

[1863-kruskal.cpp](mst/1863-kruskal.cpp)

### Prim

> 问题背景：HDU1863：http://acm.hdu.edu.cn/showproblem.php?pid=1863

[1863-prim.cpp](mst/1863.cpp)

# Mathematics

### GCD & LCM

[gcd-lcm.cpp](mathematics/gcd-lcm.cpp)


# 其他 / Others

This repository is MIT licensed.