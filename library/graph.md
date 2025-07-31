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