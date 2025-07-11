#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
namespace rng = ranges;

template <typename F>
class y_combinator_result {
  F f;

public:
  template <typename T>
  explicit y_combinator_result(T &&_f) : f { std::forward<T>(_f) } {
  }

  template <typename... Ts>
  decltype(auto) operator()(Ts... args) {
    return f(ref(*this), std::forward<Ts>(args)...);
  }
};

template <typename F>
decltype(auto) y_combinator(F &&f) {
  return y_combinator_result<decay_t<F>> { std::forward<F>(f) };
}

template <typename T>
concept PrintableRange = rng::range<T> && !convertible_to<T, string>;

template <PrintableRange T>
ostream &operator<<(ostream &out, const T &r) {
  for (const auto &v : r) out << v << ' ';
  return out;
}

template <PrintableRange T>
istream &operator>>(istream &in, T &r) {
  for (auto &v : r) in >> v;
  return in;
}

namespace io {

template <typename... Ts>
inline void print(Ts &&...args) {
  ((cout << std::forward<Ts>(args) << ' '), ...);
}

template <typename... Ts>
inline void println(Ts &&...args) {
  io::print(std::forward<Ts>(args)...);
  cout << '\n';
}

template <typename... Ts>
inline void printf(std::format_string<Ts...> fmt, Ts &&...args) {
  cout << format(fmt, std::forward<Ts>(args)...);
}

template <typename... Ts>
inline void printfln(std::format_string<Ts...> fmt, Ts &&...args) {
  io::printf(fmt, std::forward<Ts>(args)...);
  cout << '\n';
}

}  // namespace io

/*------------------------------have-fun------------------------------*/

void solve();

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t { 1 };
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

void solve() {
}