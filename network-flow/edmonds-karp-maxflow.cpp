// Edmonds-Karp 求解最大流 
// 强推下面这篇文章！ 
// http://www.cnblogs.com/ZJUT-jiangnan/p/3632525.html

int pre[MAXN], visited[MAXN];

/**
 * 更新残量网络 
 * @param int u    起点 
 * @param int flow 更新的流量 
 */
void update_residual_network(int u, int flow) 
{
  while (pre[u] != -1)
  {
    map[pre[u]][u] -= flow;     // 正向边减去流量 
    map[u][pre[u]] += flow;     // 反向边加上流量
    u = pre[u];
  }
}

/**
 * 寻找可行的增广路 
 * @param int start     起点 
 * @param int terminal  终点 
 */
int find_path(int start, int terminal)
{
  // 初始化标记数组
  memset(visited, 0, sizeof visited);
  memset(pre, -1, sizeof pre);
  visited[start] = 1;
   
  // BFS
  int min = INF;
  queue<int> Q;
  Q.push(start);
  
  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();
    // 如果当前点已经是终点了，退出 
    if (cur == terminal) {
      break;
    }
    // 否则，对于该点连接的下一个节点，继续搜索 
    for (int i = 0; i < m; i++)
    {
      if (!visited[i] && map[cur][i] != 0) {
        Q.push(i);             // 把当前点加入 BFS 队列 
        min = min < map[cur][i] ? min : map[cur][i];     // 更新 delta 的最小值 
        pre[i] = cur;          // 更新增广路的路径
        visited[i] = 1;        // 标记节点已访问 
      }
    } // for
  } // while
  // 找不到更多的增广路了 
  if (pre[terminal] == -1) {
    return 0;
  }
  // 如果找到了，返回增广路的最小值
  return min;    
}

/**
 * Edmonds Karp 算法主函数 
 * @param int start     起点 
 * @param int terminal  终点 
 */
int edmonds_karp(int start, int terminal)
{
  int newFlow = 0, maxFlow = 0;
  // 当存在可行流的时候，不断增广 
  do {
    newFlow = find_path(start, terminal);
    update_residual_network(terminal, newFlow);
    maxFlow += newFlow;
  } while (newFlow != 0);
  
  return maxFlow;
}
