# 重みなし木
## getdist
```cpp
// 各ノードとの距離を返す
// d[i] : iとstartの距離
// G    : 重みなしグラフ
VLL getdist(ll start, const VVLL& G) {
  VLL d(G.size(), INFLL);
  d[start] = 0;
  queue<ll> q;
  q.push(start);
  while (!q.empty()) {
    ll pos = q.front();
    q.pop();
    for (ll next : G[pos]) {
      if (d[next] == INFLL) {
        d[next] = d[pos] + 1;
        q.push(next);
      }
    }
  }
  return d;
}
```

# 重み付き無向グラフ
## ダイクストラ法
```cpp
struct Edge {
  ll to;
  ll cost;
};

VLL dijkstra(const vector<vector<Edge>>& G, ll start) {
  VLL d(G.size(), INFLL);
  priority_queue<PLL, vector<PLL>, greater<PLL>> q;
  d[start] = 0;
  q.push({0, start});

  while (!q.empty()) {
    auto [cost, pos] = q.top();
    q.pop();
    if (cost > d[pos])
      continue;
    for (auto& e : G[pos]) {
      if (chmin(d[e.to], cost + e.cost)) {
        q.push({d[e.to], e.to});
      }
    }
  }
  return d;
}
```