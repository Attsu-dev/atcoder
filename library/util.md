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