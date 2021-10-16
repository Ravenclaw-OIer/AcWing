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
const int INF = 2e9 + 1;
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
struct Youmu {
  int pos, val;
  bool operator<(const Youmu& rhs) const {return val < rhs.val; }
  Youmu(int val = 0, int pos = 0): pos(pos), val(val) {}
} a[100100], ans[100100];
int p[100100], pre[100100], nxt[100100], n;
int main() {
  rd(n);
  repn(i, n) {rd(a[i].val); a[i].pos = i;}
  sort(a + 1, a + n + 1);
  a[0].val = -INF; a[n + 1].val = INF;
  repn(i, n) {p[a[i].pos] = i; pre[i] = i - 1; nxt[i] = i + 1; }
  for (int i = n; i >= 2; i--) {
    int j = p[i], l = pre[j], r = nxt[j];
    int ldif = abs(a[j].val - a[l].val), rdif = abs(a[j].val - a[r].val); 
    if (ldif <= rdif) ans[i] = Youmu(ldif, a[l].pos); else ans[i] = Youmu(rdif, a[r].pos);
    nxt[l] = r; pre[r] = l; // delete i from doubly-linked list
  }
  repn(i, n) if (i - 1) printf("%d %d\n", ans[i].val, ans[i].pos);
}