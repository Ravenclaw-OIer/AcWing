/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 防线
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/122/
// Written by RavenclawOIer on 08-13-2021

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
int n;
const int N = 200020;
int s[N], e[N], d[N], st, ed, sum[N];
int get_sum(int pos) {
//  if (sum[pos] != -1) return sum[pos];
  int res = 0;
  rep(i, n) {
    if (s[i] <= pos) {
      res += (min(pos, e[i]) - s[i]) / d[i] + 1;
    }
  }
  return  res;
}
void solve() {
  rd(n);
  rep(i, n) {
    rd(s[i]);
    rd(e[i]);
    rd(d[i]);
    chmin(st, s[i]);
    chmax(ed, e[i]);
  }

  if (get_sum(ed) % 2 == 0) {
    puts("There's no weakness.");
    return;
  }
  int L = st, R = ed;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if ((get_sum(mid) - get_sum(L - 1)) % 2 == 1) R = mid - 1; else L = mid + 1;
  }
  cout << L << ' ' << get_sum(L) - get_sum(L - 1) << endl;
}
int main() {
  int tcs;
  rd(tcs);
  while (tcs--) {
    solve();
  }
}
