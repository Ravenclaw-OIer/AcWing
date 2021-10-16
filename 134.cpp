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
const int N = 1000100;
int group[N];
int main() {
  int n, kase = 0;
  while (rd(n)) {
    queue<int> p, q[1010];
    repn(i, n) {
      int t;
      rd(t);
      while (t--) {
        int x;
        rd(x);
        group[x] = i;
      }
    }
    string opt;
    printf("Scenario #%d\n", ++kase);
    while (cin >> opt) {
      if (opt == "ENQUEUE") {
        int id;
        rd(id);
        q[group[id]].push(id);
        if (q[group[id]].size() == 1) p.push(group[id]);
      } else if (opt == "DEQUEUE") {
        int frontGroup = p.front();
        printf("%d\n", q[frontGroup].front());
        q[frontGroup].pop();
        if (q[frontGroup].empty()) p.pop();
      } else break;
    }
    puts("");
  }
}
