# Sieve of Eratosthenes

## Prime Sieve

```cpp
auto make_sieve(size_t N) {
  vector<char> sieve(N + 1, true);
  for (size_t i = 2; i * i <= N; ++i) {
    if (!sieve[i]) continue;
    for (size_t x = i * i; x <= N; x += i) {
      sieve[x] = false;
    }
  }
  return sieve;
}
```

## Largest Prime Factor

```cpp
auto make_lpf(size_t N) {
  vector<int> lpf(N + 1);
  for (size_t i = 2; i <= N; ++i) {
    if (lpf[i]) continue;
    for (size_t x = i; x <= N; x += i) {
      lpf[x] = i;
    }
  }
  return lpf;
}
```

## Smallest Prime Factor

```cpp
auto make_spf(size_t N) {
  vector<int> spf(N + 1);
  for (size_t i = 2; i <= N; ++i) {
    if (spf[i]) continue;
    for (size_t x = i; x <= N; x += i) {
      if (spf[x]) continue;
      spf[x] = i;
    }
  }
  return spf;
}
```

## Prime Generation

```cpp
auto make_primes(size_t N) {
  vector<int> primes;
  vector<char> sieve(N + 1, true);
  for (size_t i = 2; i <= N; ++i) {
    if (!sieve[i]) continue;
    primes.push_back(i);
    for (size_t x = i * i; x <= N; x += i) {
      sieve[x] = false;
    }
  }
  return primes;
}
```
