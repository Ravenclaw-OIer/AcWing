/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 最高的牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/103/
// Written by RavenclawOIer on 08-06-2021

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
ttt inline void rd(T& x) {
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
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
set<pii> exist;
const int N = 10010;
int d[N], c[N];
int main() {
  int n, p, h, m;
  rd(n); rd(p); rd(h); rd(m);
  rep(i, m) {
    int x, y;
    rd(x);
    rd(y);
    if (x > y) swap(x, y);
    if (exist.count(make_pair(x, y))) continue;
    else exist.insert(make_pair(x, y));
    d[x + 1]--;
    d[y]++;
  }
  repn(i, n) {
    c[i] = c[i - 1] + d[i];
    printf("%d\n", h + c[i]);
  }
}
