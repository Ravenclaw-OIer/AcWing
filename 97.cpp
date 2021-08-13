/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 费解的开关
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/97/
// Written by RavenclawOIer on 07-30-2021

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) ;
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
bool a[6][6], b[6][6];
void click(int x, int y) {
  eprintf("Clicked on (%d, %d)\n", x, y);
  a[x][y] ^= 1;
  if (x != 0) a[x - 1][y] ^= 1;
  if (y != 0) a[x][y - 1] ^= 1;
  if (x != 4) a[x + 1][y] ^= 1;
  if (y != 4) a[x][y + 1] ^= 1;
  rep(i, 5) { rep(j, 5) eprintf("%d ", a[i][j]); eprintf("\n");}
}
int main() {
  int T;
  rd(T);
  while (T--) {
    rep(i, 5) {
      string s;
      cin >> s;
      rep(j, 5) b[i][j] = s[j] - '0';
    }
    int ans = INF;
    for (int mask = 0; mask <= 31; mask++) {
      eprintf("%d\n", mask);
      int res = 0;
      rep(i, 5) rep(j, 5) a[i][j] = b[i][j];
      rep(i, 5) if (mask & (1 << i)) {
        click(0, i);
        res++;
      }
      for (int i = 1; i < 5; i++) rep(j, 5) if (!a[i - 1][j]) {
          click(i, j);
          res++;
        }
      rep(j, 5) if (!a[4][j]) goto BAD;
      chmin(ans, res);
      BAD:continue;
    }
    if (ans > 6) puts("-1"); else printf("%d\n", ans);
  }
}
