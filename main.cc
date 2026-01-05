#include <bits/stdc++.h>
using namespace std;
namespace stdv = views;
namespace stdr = ranges;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

template <typename R>
concept Printable = stdr::range<R> && !convertible_to<R, string_view>;

template <Printable R>
ostream& operator<<(ostream& out, const R& r) {
  for (const auto& v : r) out << v << ' ';
  return out;
}

template <Printable R>
istream& operator>>(istream& in, R& r) {
  for (auto& v : r) in >> v;
  return in;
}

template <typename T, typename U>
istream& operator>>(istream& in, pair<T, U>& p) {
  return in >> p.first >> p.second;
}

template <typename... Ts>
istream& operator>>(istream& in, tuple<Ts...>& t) {
  [&]<size_t... Is>(index_sequence<Is...>) {
    ((in >> get<Is>(t)), ...);
  }(index_sequence_for<Ts...>{});
  return in;
}

namespace io {

template <typename... Ts>
void print(Ts&&... args) {
  ((cout << std::forward<Ts>(args) << ' '), ...);
}

template <typename... Ts>
void println(Ts&&... args) {
  io::print(std::forward<Ts>(args)...);
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

  int t{1};
  cin >> t;
  while (t--) {
    solve();
  }
}

void solve() {}