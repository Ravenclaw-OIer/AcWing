// Problem: 赶牛入圈
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/123/
// Written by RavenclawOIer on 08-13-2021

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
int c, n, nn;
const int N = 510;
int a[N][N];
int x[N], y[N], raw_x[N], raw_y[N];
vector<int> raw;
int query(int x) {
  return lower_bound(raw.begin(), raw.end(), x) - raw.begin();
}

bool check(int len) {
  for (int x1 = 1, x2 = 1; x2 <= nn; x2++) {
    while (raw[x2] - raw[x1] + 1 > len) x1++;
    for (int y1 = 1, y2 = 1; y2 <= nn; y2++) {
      while (raw[y2] - raw[y1] + 1 > len) y1++;
      if (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] >= c) return true;
    }
  }
  return false;
}

int main() {
  rd(c);
  rd(n);
  raw.push_back(0);
  repn(i, n) {
    rd(x[i]);
    rd(y[i]);
    raw.push_back(x[i]);
    raw.push_back(y[i]);
  }
  sort(raw.begin(), raw.end());
  raw.erase(unique(raw.begin(), raw.end()), raw.end());
  nn = raw.size();
  repn(i, n) { a[query(x[i])][query(y[i])]++; }
  repn(i, nn) repn(j, nn) a[i][j] +=
      a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  int L = 1, R = 10000, ans;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      ans = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  cout << ans << endl;
}
