/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 防晒
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/112/
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
int n, m;
const int N = 2600;
struct Cow {
  int minSPF, maxSPF;
} a[N];
struct Lotion {
  int SPF, cover;
} b[N];
int main() {
  rd(n);
  rd(m);
  rep(i, n) {
    rd(a[i].minSPF);
    rd(a[i].maxSPF);
  }
  sort(a, a + n, [](const Cow& a, const Cow& b) {
    return a.minSPF > b.minSPF;
  });
  rep(i, m) {
    rd(b[i].SPF);
    rd(b[i].cover);
  }
  sort(b, b + m, [](const Lotion& a, const Lotion& b) {
    return a.SPF > b.SPF;
  });
  int ans = 0;
  rep(i, n)
    rep(j, m)  
      if (b[j].SPF >= a[i].minSPF &&
          b[j].SPF <= a[i].maxSPF &&
          b[j].cover > 0) {
            b[j].cover--;
            ans++;
            break;
          }
  cout << ans << endl;
  
}
