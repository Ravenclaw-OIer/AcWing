// Problem: 畜栏预定
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/113/
// Written by RavenclawOIer on 08-27-2021

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
const int N = 50050;

struct Cow {
  int l, r, id, ans;
} a[N];

int main() {
  int n;
  rd(n);
  repn(i, n) {
    a[i].id = i;
    rd(a[i].l);
    rd(a[i].r);
  }
  sort(a + 1, a + n + 1, [](const Cow a, const Cow b) { return a.l < b.l; });
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  repn(i, n) {
    int sz = pq.size();
    if (!pq.empty() && pq.top().first < a[i].l) {
      a[i].ans = pq.top().second;
      pq.pop();
      pq.push(make_pair(a[i].r, a[i].ans));
    } else {
      a[i].ans = ++sz;
      pq.push(make_pair(a[i].r, a[i].ans));
    }
  }
  vector<int> ans(n + 1);
  repn(i, n) ans[a[i].id] = a[i].ans;
  printf("%d\n", pq.size());
  repn(i, n) printf("%d\n", ans[i]);
}