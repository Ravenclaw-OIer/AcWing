/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 递归实现排列型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/96/
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
const int N = 14;
int a[N], n;
bool vis[N];
void dfs(int dep) {
  if (dep == n + 1) {
    repn(i, n) printf("%d ", a[i]);
    puts("");
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = true;
      a[dep] = i;
      dfs(dep + 1);
      a[dep] = 0;
      vis[i] = false;
    }
  }
} 
int main() {
  rd(n);
  dfs(1);
}
