# 二分探索
## lower_b
```cpp
// ソートされた配列内で、key以上かつ一番左側のインデックスを返す
ll lower_b(const VLL& v, ll key) {
    return distance(v.begin(), lower_bound(v.begin(), v.end(), key));
}
```
## upper_b
```cpp
// ソートされた配列内で、keyより大きいかつ一番左側のインデックスを返す
ll upper_b(const VLL& v, ll key) {
    return distance(v.begin(), upper_bound(v.begin(), v.end(), key));
}
```
## めぐる式
```cpp
auto isOK = [&](ll x) {
    
};
ll ok = N + 1;
ll ng = -1;
while (abs(ok - ng) > 1) {
ll mid = (ok + ng) / 2;
if (isOK(mid))
    ok = mid;
else
    ng = mid;
}
print(ok);
```

# 行列計算用の構造体
```cpp
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
```

# 組合せ（nCr）
```cpp
using mint = modint1000000007;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// COMを使うための前処理
void ncrInit() {
  const int MOD = mint::mod();
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i;
    inv[i] = MOD - inv[MOD % i] * (MOD / i);
    finv[i] = finv[i - 1] * inv[i];
  }
}

mint ncr(int n, int r) {
  if (n < r)
    return 0;
  if (n < 0 || r < 0)
    return 0;
  return fac[n] * finv[r] * finv[n - r];
}
```