# Binary Search

## `[l, r]` way

```cpp
template <class T, class F>
T find_first_false(T l, T r, F&& f) {
  --l; ++r;
  while (r - l > 1) {
    T m = midpoint(l, r);
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}
```

## `(l, r)` way

```cpp
template <class T, class F>
T find_first_false(T l, T r, F&& f) {
  T ans = -1;
  while (l <= r) {
    T m = midpoint(l, r);
    if (f(m)) {
      l = m + 1;
    } else {
      ans = m;
      r = m - 1;
    }
  }
  return ans;
}
```

## `[l, r)` way

```cpp
template <class T, class F>
T find_first_false(T l, T r, F&& f) {
  ++r;
  while (l < r) {
    T m = midpoint(l, r);
    if (f(m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
}
```

## `C++20`

```cpp
using rng = ranges;
auto find_first_false(auto l, auto r, auto&& f) {
  return *rng::partition_point(views::iota(l, r), forward<decltype(f)>(f));
}
```
