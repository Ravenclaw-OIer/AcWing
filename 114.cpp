// Problem: 雷达设备
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/114/
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
int n, r;
const int N = 1010;
pii a[N];
#define x first
#define y second
pair<double, double> in[N];
int dist(pii a, pii b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
  rd(n);
  rd(r);
  repn(i, n) {
    rd(a[i].x);
    rd(a[i].y);
    if (a[i].y > r) return !puts("-1");
  }
  repn(i, n) {
    int dx = r * r - dist(a[i], make_pair(a[i].x, 0));
    in[i].first = a[i].x - sqrt(dx);
    in[i].second = a[i].x + sqrt(dx);
  }
  sort(in + 1, in + n + 1,
       [](const pair<double, double>& a, const pair<double, double>& b) {
         return a.first < b.first;
       });
  double last = -1000000000;
  int ans = 0;
  repn(i, n) {
    if (in[i].first > last) {
      last = in[i].second;
      ans++;
    } else chmin(last, in[i].second);
  }
  printf("%d\n", ans);
}
