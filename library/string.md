# 括弧列
## 括弧列判定
```cpp
// Sは括弧列か？
bool is_kakko(string S) {
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') cnt += 1;
		if (S[i] == ')') cnt -= 1;
		if (cnt < 0) return false;
	}
	return (cnt == 0);
}
```