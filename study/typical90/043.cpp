#if !__INCLUDE_LEVEL__
#include __FILE__

struct Node {
  ll y, x, d;
};

int main() {
  int H, W;
  cin >> H >> W;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;
  VS S(H);
  cin >> S;

  deque<Node> q;

  vector c(H, VVLL(W, VLL(4, INFLL)));
  rep(d, 4) {
    q.push_back(Node{sy, sx, d});
    c[sy][sx][d] = 0;
  }

  while (true) {
    auto [y, x, dir] = q.front();
    q.pop_front();
    ll cost = c[y][x][dir];
    if (y == gy && x == gx) {
      print(c[y][x][dir]);
      return 0;
    }
    rep(d, 4) {
      ll nx = x + dx[d];
      ll ny = y + dy[d];
      if (!(0 <= nx && nx < W && 0 <= ny && ny < H))
        continue;
      if (S[ny][nx] == '#')
        continue;
      if (d == dir) {
        if (chmin(c[ny][nx][d], cost)) {
          q.push_front(Node{ny, nx, d});
        }
      } else {
        if (chmin(c[ny][nx][d], cost + 1)) {
          q.push_back(Node{ny, nx, d});
        }
      }
    }
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
struct Vec2 {
  ll y = 0, x = 0;
  Vec2() = default;
  Vec2(ll Y, ll X) : y(Y), x(X) {}
  Vec2 operator+(const Vec2& o) const { return {y + o.y, x + o.x}; }
  Vec2 operator-(const Vec2& o) const { return {y - o.y, x - o.x}; }
  Vec2 operator*(ll k) const { return {k * y, k * x}; }
  Vec2& operator+=(const Vec2& o) {
    y += o.y;
    x += o.x;
    return *this;
  }
  Vec2& operator-=(const Vec2& o) {
    y -= o.y;
    x -= o.x;
    return *this;
  }
  bool operator==(const Vec2& o) const { return y == o.y && x == o.x; }
  bool operator!=(const Vec2& o) const { return !(*this == o); }
  auto as_pair() const { return std::tie(y, x); }
  bool operator<(const Vec2& o) const { return as_pair() < o.as_pair(); }
};
map<char, Vec2> UDLR_to_Vec2 = {{'U', Vec2(-1, 0)},
                                {'D', Vec2(1, 0)},
                                {'L', Vec2(0, -1)},
                                {'R', Vec2(0, 1)}};
#endif
