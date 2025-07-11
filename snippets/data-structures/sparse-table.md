# Sparse Table

## Construction

Construction of sparse table from `vector<int> a` of size `n`.

```cpp
constexpr size_t K = 20;
vector<vector<int>> st(K + 1, vector<int>(n));
copy(a.begin(), a.end(), st[0].begin());
for (int i = 1; i <= K; ++i) {
  for (int j = 0; j + (1 << i) <= n; ++j) {
    st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }
}
```

Here `f(x, y)` is the query function like, `min`, `max`, sum, etc.

## Sum queries

Sum query in the interval `[l, r]`.

```cpp
ll sum = 0;
for (int i = K; i >= 0; i--) {
  if ((1 << i) <= r - l + 1) {
    sum += st[i][l];
    l += (1 << i);
  }
}
```

## `min/max` queries

`min/max` query in the interval `[l, r]`.

```cpp
int i = lg[r - l + 1];
int res = min(st[i][l], st[i][r - (1 << i) + 1]);
```

## Computation of `log2_floor`

### `C++20`

```cpp
#include <bit>
int log2_floor(unsigned long n) {
  return bit_width(n) - 1;
}
```

### Pre-`C++20`

```cpp
int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
```

### Precomputation

```cpp
vector<int> lg(n + 1);
lg[1] = 0;
for (int i = 2; i <= m; i++) {
  lg[i] = lg[i / 2] + 1;
}
```
