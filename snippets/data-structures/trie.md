# Trie

```cpp
struct Node {
  array<int, 26> next{};
  Node() { next.fill(-1); }
};
vector<Node> trie{{}};

void add_string(string_view s) {
  int v = 0;
  for (auto c : s) {
    c -= 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[c];
  }
}

void traverse(string_view s) {
  int v = 0;
  for (auto c : s) {
    c -= 'a';
    v = trie[v].next[c];
    if (v == -1) break;
  }
}
```
