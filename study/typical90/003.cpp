#if !__INCLUDE_LEVEL__
#include __FILE__

void getdist(ll start, VLL& d, const VVLL& G) {
  queue<ll> q;
  q.push(start);
  d[start] = 0;
  while (!q.empty()) {
    ll pos = q.front();
    q.pop();

    for (ll next : G[pos]) {
      if (d[next] == LLONG_MAX) {
        d[next] = d[pos] + 1;
        q.push(next);
      }
    }
  }
}

int main() {
  ll N;
  cin >> N;
  VVLL G(N);
  rep(i, N - 1) {
    ll A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  VLL d(N, LLONG_MAX);
  getdist(0, d, G);
  ll max_i = distance(d.begin(), max_element(all(d)));
  dbg(max_i);
  VLL d2(N, LLONG_MAX);
  getdist(max_i, d2, G);

  print(*max_element(all(d2)) + 1);
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

const double pi = 3.141592653589793238;
const int inf = 1073741823;
const ll infl = 1LL << 60;
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
