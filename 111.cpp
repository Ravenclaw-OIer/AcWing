/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#include <bits/stdc++.h>
#define int long long
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
const int N = 5000500;
int a[N], b[N];
LL calc(int l, int r, int M) {
 // cerr << l << ' ' << r << endl;
  int x = 0;
  for (int i = l; i < r; i++) b[x++] = a[i];
  sort(b, b + x);
  int m = M;
  if ((r - l) / 2 < M) {
    m = (r - l) >> 1;
  } else m = M;
  int ret = 0, st = 0, ed = x - 1;
  rep(i, m) {
    ret += (b[st] - b[ed]) * (b[st] - b[ed]);
    st++;
    ed--;
  }
  return ret;
}
signed main() {
  int k; rd(k);
  while (k--) {
    int n, m, t, ans = 0;
    rd(n); rd(m); rd(t);
    rep(i, n) rd(a[i]);
    int L = 0, R = 0;
    while (L < n && R < n) {
      int len = 1;
      while (len) {
   //     cerr << len << endl;
        if (R + len <= n && calc(L, R + len, m) <= t) {
          R += len;
          len <<= 1;
        } else len >>= 1;
      }
      ans++;
      L = R;
    }
    printf("%lld\n", ans);
  }
}
