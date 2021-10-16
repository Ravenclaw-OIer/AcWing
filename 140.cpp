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
string s;
int n;
typedef unsigned long long ull;
ull h[1000100], power[1000100];
const int base = 13331;
void initHash() {
  power[0] = 1;
  repn(i, n) {
    h[i] = h[i - 1] * base + (s[i] - 'a' + 1);
    power[i] = power[i - 1] * base;
  }
}
ull getRangeHash(int l, int r) { return h[r] - h[l - 1] * power[r - l + 1]; }
int main() {
  cin >> s;
  n = s.length();
  s = "$" + s;
  initHash();
  int q;
  rd(q);
  while (q--) {
    int l1, r1, l2, r2;
    rd(l1);
    rd(r1);
    rd(l2);
    rd(r2);
    if (getRangeHash(l1, r1) == getRangeHash(l2, r2)) puts("Yes"); else puts("No");
  }
}
