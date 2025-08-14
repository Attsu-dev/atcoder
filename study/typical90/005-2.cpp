#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
  vector<vector<long long>> a;
  int H, W;
  long long mod;

  Matrix(int h, int w, long long mod = 1e9 + 7, bool ident = false)
      : H(h), W(w), mod(mod) {
    a.assign(h, vector<long long>(w, 0));
    if (ident) {
      for (int i = 0; i < min(h, w); i++)
        a[i][i] = 1;
    }
  }

  // []アクセス用
  vector<long long>& operator[](int i) { return a[i]; }
  const vector<long long>& operator[](int i) const { return a[i]; }

  // 行列積
  Matrix operator*(const Matrix& o) const {
    assert(W == o.H);
    Matrix res(H, o.W, mod);
    for (int i = 0; i < H; i++) {
      for (int k = 0; k < W; k++) {
        if (a[i][k] == 0)
          continue;
        long long aik = a[i][k];
        for (int j = 0; j < o.W; j++) {
          res.a[i][j] = (res.a[i][j] + aik * o.a[k][j]) % mod;
        }
      }
    }
    return res;
  }

  // 累乗
  Matrix pow(long long exp) const {
    assert(H == W);
    Matrix base = *this;
    Matrix res(H, H, mod, true);  // 単位行列
    while (exp > 0) {
      if (exp & 1)
        res = res * base;
      base = base * base;
      exp >>= 1;
    }
    return res;
  }
};

int main() {
  ll N, B, K;
  cin >> N >> B >> K;
  VLL c(K);
  cin >> c;
  Matrix A(B, B);
  rep(i, B) {
    for (ll j : c) {
      ll nj = (10 * i + j) % B;
      A[i][nj]++;
    }
  }
  Matrix E(B, 1, 1e9 + 7, true);
  print((A.pow(N) * E)[0][0]);
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
