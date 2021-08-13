/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 超快速排序
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/109/
// Written by RavenclawOIer on 08-06-2021

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int INF = 0x3f3f3f3f;
ttt inline int rd(T& x) {
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
const int N = 500050;
int a[N], tmp[N], ans;
void merge(int l, int r) {
  if (r - l <= 1) return; // border of ~~life~~ recursion
  int mid = (l + r) >> 1;
  merge(l, mid);
  merge(mid, r);
  int L = l, M = mid, cur = l;  // start merging
  while (cur < r) {
    if (L >= mid || (M < r && a[L] > a[M])) {
      // either we've already narrowed the range
      // to the second half, since it is backtracked
      // we can be sure that it will go to the second half
      // or we have an inversion, which should be counted
      tmp[cur++] = a[M++];
      ans += (mid - L);
     } else {
      tmp[cur++] = a[L++];
    }
  }
  for (int i = l; i < r; i++) a[i] = tmp[i];
}
signed main() {
  while (rd(n)) {
    rep(i, n) rd(a[i]);
    ans = 0;
    merge(0, n);
    printf("%lld\n", ans);
  }
}
