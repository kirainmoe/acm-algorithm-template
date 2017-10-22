/* Edmonds Karp 算法 ——《算法竞赛入门经典》中的模板 */
/* 不太好理解，建议用另一个比较好写的模板 */
struct Edge {
  int from ,to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(F) {}
  }
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;
  vector<int> G[MAXN];
  int a[MAXN];          // 起点到 i 的可改进量 delta
  int p[MAXN];          // 最短路树上 p 的入弧
  
  void init(int n)
  {
    for (int i = 0; i < n; i++)
    {
      G[i].clear();
    }
    
    edges.clear();
  }
  
  void addEdge(int from, int to, int cap)
  {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));    // 反向弧
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  
  int maxFlow(int s, int t)
  {
    int flow = 0;
    while (true)
    {
      memset(a, 0, sizeof a);
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      
      while (!Q.empty())
      {
        int x = Q.front();
        Q.pop();
        
        for (unsigned int i = 0; i < G[x].size(); i++)
        {
          Edge& e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        
        if (a[t]) {
          break;
        }
      } // while !Q.empty()
      if (!a[t])
        break;
      // 更新残量网络 
      for (int u = t; u != s; u = edges[p[u]].from)
      {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    } // while true
    return flow;
  }
};
