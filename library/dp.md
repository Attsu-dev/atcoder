# 桁DP
## 余りを持って桁DP
- Bで割り切れるN桁の数字が何通りあるか？
- dp[上から何桁目][現時点でのBで割った余り] = 通り数
```cpp
VVLL dp(N + 1, VLL(B));
  dp[0][0] = 1;
  rep(i, N) {
    rep(j, B) {
      rep(k, 10) {
        ll nj = (10 * j + k) % B;
        dp[i + 1][nj] += dp[i][j];
        dp[i + 1][nj] %= mod;
      }
    }
  }
```