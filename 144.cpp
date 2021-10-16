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
#define eprintf(...) ;//fprintf(stderr, __VA_ARGS__)
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
  int nxt[27];
  int cnt;
} trie[1000100];
int tot = 0;
void insert(string str) {
  int cur = 0;
  rep(i, str.length()) {
    int c = str[i] - 'a';
    if (!trie[cur].nxt[c]) trie[cur].nxt[c] = ++tot;
    cur = trie[cur].nxt[c];
  }
  eprintf("cur = %d\n", cur);
  trie[cur].cnt++;
}
int query(string str) {
  int cur = 0, ans = 0;
  rep(i, str.length()) {
    eprintf("str[%d]\n", i);
    int c = str[i] - 'a';
    cur = trie[cur].nxt[c];
    if (!cur) break;
    ans += trie[cur].cnt;
  }
 // ans += trie[cur].cnt;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  while (n--) {string s; cin >> s; insert(s); }
  while (m--) {string s; cin >> s; cout << query(s) << endl;}
}
