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
const int N = 300030;
int sum[N], n, m;
int main() {
  rd(n); rd(m); repn(i, n) {
    int x; rd(x);
    sum[i] = sum[i - 1] + x;
  }
  deque<int> q;
  int ans = sum[1];
  q.push_back(0);
  repn(i, n) {
    while (!q.empty() && q.front() < i - m) q.pop_front();
    chmax(ans, sum[i] - sum[q.front()]); 
    while (!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
    q.push_back(i);
  }
  printf("%d\n", ans);
}
