# Modular Arithmetic

## Binary Exponentiation

### Recursive implementation

```cpp
constexpr ll mod = 1'000'000'007;
ll modpow(ll a, ll n, ll mod = mod) {
  if (n == 0) return 1;
  ll res = modpow(a, n / 2, mod);
  res = (res * res) % mod;
  if (n % 2 == 1) res = (res * a) % mod;
  return res;
}
```

### Iterative implementation

```cpp
constexpr ll mod = 1'000'000'007;
ll modpow(ll a, ll n, ll mod = mod) {
  a %= mod; ll res = 1;
  while (n > 0) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}
```

## Modular inverse

### Using binary exponentiation

```cpp
ll modinv(ll a, ll mod = mod) {
  return modpow(a, mod - 2, mod);
}
```

### Using Euclidean Division

[Explanation](https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-for-prime-moduli-using-euclidean-division)

```cpp
ll modinv(ll a, ll mod = mod) {
  if (a <= 1LL) return a;
  return mod - (ll)(mod / a) * modinv(mod % a) % mod;
}
```

Modular inverse of the range `[1, mod - 1]` in `O(mod)`

```cpp
vector<ll> inverse(mod);
inverse[1] = 1;
for (ll a = 2; a < mod; ++a) {
  inverse[a] = mod - (mod / a) * inverse[mod % a] % mod;
} 
```

## Modular multiplication

[Explanation](https://cs.stackexchange.com/questions/77016/modular-multiplication)

```cpp
ull modmult(ull a, ull b, ull mod = mod) {
  ld x; ull c; ll r;
  if (a >= mod) a %= mod;
  if (b >= mod) b %= mod;
  x = a;
  c = x * b / mod;
  r = (ll)(a * b - c * mod) % (ll)mod;
  return r < 0 ? r + mod : r;
}
```
