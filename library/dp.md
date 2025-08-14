# DP全般
## 行列遷移
```math
A\left[
\begin{matrix} dp[i][0] \\ dp[i][1] \\ dp[i][2]\end{matrix}
\right] = \left[
\begin{matrix} dp[i+1][0] \\ dp[i+1][1] \\ dp[i+1][2]\end{matrix}
\right]
```
となるような正方行列Aが存在するならば使える。
```math
A^N\left[
\begin{matrix} dp[i][0] \\ dp[i][1] \\ dp[i][2]\end{matrix}
\right] = \left[
\begin{matrix} dp[N][0] \\ dp[N][1] \\ dp[N][2]\end{matrix}
\right]
```
### 計算量
- $O(B^3logN)$
  - B : 行列のサイズ
- 繰り返し二乗法を使う（$A^1, A^2, A^4, A^8, ...$を前もって求めておく）
### 例題
- [N桁のBの倍数を数える](../study/typical90/005-2.cpp)

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