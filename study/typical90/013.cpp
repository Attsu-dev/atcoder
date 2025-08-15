#if !__INCLUDE_LEVEL__
#include __FILE__

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

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  rep(i, M) {
    ll A, B, C;
    cin >> A >> B >> C;
    A--, B--;
    Edge E;
    E.to = B;
    E.cost = C;
    G[A].push_back(E);
    E.to = A;
    G[B].push_back(E);
  }

  VLL go = dijkstra(G, 0);
  VLL back = dijkstra(G, N - 1);
  rep(i, N) {
    print(go[i] + back[i]);
  }
}

#else
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
struct Init {
  Init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(13);
  }
} init;

using ll = long long;
using ull = unsigned long long;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using PLL = pair<ll, ll>;
using VS = vector<string>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define eps (1e-10)
#define Equals(a, b) (fabs((a) - (b)) < eps)
#define debug(x) cerr << #x << " = " << x << el

const double PI = 3.141592653589793238;
const int INF = 1073741823;
const ll INFLL = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 != (int)v.size() ? " " : "");
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& in : v)
    is >> in;
  return is;
}
void print() {
  cout << el;
}
template <typename T>
void print(const T& t) {
  cout << t << el;
}
template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail) {
  cout << head << spa;
  print(tail...);
}
void dbg() {
  cerr << el;
}
template <typename T>
void dbg(const T& t) {
  cerr << t << el;
}
template <typename Head, typename... Tail>
void dbg(const Head& head, const Tail&... tail) {
  cerr << head << spa;
  print(tail...);
}
template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b) {
  bool compare = a < b;
  if (compare)
    a = b;
  return compare;
}
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
  bool compare = a > b;
  if (compare)
    a = b;
  return compare;
}
void YesNo(bool b) {
  cout << (b ? "Yes" : "No") << el;
}

#endif
