#if !__INCLUDE_LEVEL__
#include __FILE__

struct Task {
  ll D;
  ll C;
  ll S;
};

bool task_cmp(const Task& t1, const Task& t2) {
  return t1.D < t2.D;
}

int main() {
  ll N;
  cin >> N;
  vector<Task> T(N);
  rep(i, N) {
    cin >> T[i].D >> T[i].C >> T[i].S;
    // T[i].D--;
  }
  sort(all(T), task_cmp);

  VVLL dp(N + 1, VLL(5001));
  rep(i, N) {
    // j = 現在時刻
    FOR(j, 1, 5001) {
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - 1]);
      // 仕事iを行える場合
      if (j >= T[i].C && j <= T[i].D) {
        ll yes = dp[i][j - T[i].C] + T[i].S;
        chmax(dp[i + 1][j], yes);
      }
    }
  }
  // rep(i, N + 1) {
  //   rep(j, 9) {
  //     cerr << dp[i][j] << " ";
  //   }
  //   dbg();
  // }
  print(*max_element(all(dp.back())));
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
