# GCD

## `gcd(a, b)` implementation

```cpp
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
```

## Extended GCD

`extended_gcd(a, b)` return a tuple `(d, x, y)`
where d is `gcd(a, b)` and `x` and `y` are Bezout's coefficients of `a` and `b`,
such that `ax + by = d`.

[Explanation](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html)

```cpp
template <typename T>
tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) {
    return { a, 1, 0 };
  }
  auto [d, x1, y1] = extended_gcd(b, a % b);
  T x = y1;
  T y = x1 - y1 * (a / b);
  return { d, x, y };
}
```

## Binary GCD

[Explanation](https://cp-algorithms.com/algebra/euclid-algorithm.html#binary-gcd)

```cpp
[[gnu::target("popcnt")]]
uint32_t fast_gcd(uint32_t a, uint32_t b) {
  if (!a || !b) return a | b;
  uint32_t shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
```
