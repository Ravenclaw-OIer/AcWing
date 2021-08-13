/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 约数之和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/99/
// Written by RavenclawOIer on 07-30-2021

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
int n, m;
const int MOD = 9901;
vector<pii> factor;
int qpow(int a, int b = MOD - 2, int p = MOD) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
  }
  return ans % p;
}
void modmul(int& x, int y) { x = (x * y) % MOD; }
void moddiv(int& x, int y) { x = (x * qpow(y)) % MOD; }
signed main() {
  rd(n);
  if (!n) return !(puts("0"));
  rd(m);
  int nn = n;
  for (int i = 2; i <= n / i; i++) {
    if (nn % i == 0) {
      int cnt = 0;
      while (nn % i == 0) {
        nn /= i;
        cnt++;
      }
      factor.push_back(make_pair(i, cnt));
    }
  }
  if (nn != 1) factor.push_back(make_pair(nn, 1));
  int ans = 1;
  rep(i, factor.size()) {
    int p = factor[i].first, a = factor[i].second * m;
    //  cerr << p << ' ' << a << endl;
    int x = (qpow(p, a + 1) - 1) % MOD, y = p - 1;
    if (!(y % MOD)) {
     // cerr << "WARNING" << endl;
      modmul(ans, (a + 1));
    } else {
      // cerr << x << '/' << y << endl;
      moddiv(x, y);
      modmul(ans, x);
    }
  }
  printf("%lld\n", (ans + MOD) % MOD);
}
