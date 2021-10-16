/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int INF = 0x3f3f3f3f;
ttt inline T rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
  return x;
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
struct TrieNode {
  int nxt[2];
  bool terminate;
} trie[3300100];  // note the 31x space here
int root = 0, tot = 0;
void insert(int x) {
  int cur = root;
  for (int i = 30; i >= 0; i--) {
    bool bit = x & (1 << i);
    if (!trie[cur].nxt[bit]) trie[cur].nxt[bit] = ++tot;
    cur = trie[cur].nxt[bit];
  }
  trie[cur].terminate = true;
}
int query(int x) {
  int cur = root, ans = 0;
  for (int i = 30; i >= 0; i--) {
    bool bit = x & (1 << i);
    if (trie[cur].nxt[bit ^ 1]) {
      ans += (1 << i);
      cur = trie[cur].nxt[bit ^ 1];
    } else {
      cur = trie[cur].nxt[bit];
    }
  }
  return ans;
}
const int N = 100010;
int a[N];
int main() {
  int n;
  rd(n);
  repn(i, n) {
    rd(a[i]);
    insert(a[i]);
  }
  int ans = 0;
  repn(i, n) chmax(ans, query(a[i]));
  printf("%d\n", ans);
}
