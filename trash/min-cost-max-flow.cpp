#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 2333;
 
struct Edge {
  int u, v;       // 有向边的起点和终点
  int cap;        // 边的总容量
  int flow;       // 边的现有流量
  int cost;       // 单位流费用
  Edge& reverse;  // 残量网络中的反向边
  
  Edge(
    int tu = 0, int tv = 0, int tcap = 0,
    int tcost = 0, int tflow = 0
  ) {
    u = tu, v = tv, cap = tcap,
    cost = tcost, flow = tflow;
  }
};

vector<Edge> G[MAXN];

/**
 * 计算某一边的剩余流量
 * @param  e 待计算的 Edge
 * @return   返回计算后的剩余流量
 */
int getResidual(Edge e)
{
  return e.cap - e.flow;
}

/**
 * 添加一条边（包括正向和反向）
 * @param u    起点
 * @param v    终点
 * @param cap  容量
 * @param cost 费用
 */
void addEdge(int u, int v, int cap, int cost)
{
  // 正向边 
  Edge pos = Edge(u, v, cap, cost, 0, ++cnt);
  // 反向边 
  Edge rev = Edge(u, v, cap, -cost, cap, -1 + cnt++);
  
  pos.reverse = &rev;
  rev.reverse = &pos;
  
  G[u].push_back(pos);
  G[v].push_back(rev)
}

int main()
{
  return 0;
}
