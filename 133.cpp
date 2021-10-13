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
const int N = 100010;
int a[N], n;
int main() {
  while (rd(n)) {
    LL ans = 0;
    repn(i, n) {
      rd(a[i]);
    } a[n + 1] = 0;
    stack<pii> s;
    repn(i, n + 1) {
      if (!s.empty() && a[i] > s.top().first) {
        s.push(make_pair(a[i], 1));
      } else {
        int w = 0;
        while (!s.empty() && s.top().first > a[i]) {
          w += s.top().second;
          chmax(ans, 1LL * w * s.top().first);
          s.pop();
        }
        s.push(make_pair(a[i], w + 1));
      }
    }
    printf("%lld\n", ans);
  }
}
