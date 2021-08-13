// Problem: 最短Hamilton路径
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/93/
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
const int N = 21;
int dp[1 << N][N], n, w[N][N];
int main() {
  rd(n);
  rep(i, n) rep(j, n) rd(w[i][j]);
  memset(dp, INF, sizeof(dp));
  dp[1][0] = 0;
  for (int s = 1; s < (1 << n); s++)
    for (int i = 0; i < n; i++)
      if ((s >> i) & 1)  // we have went thru i before
        for (int j = 0; j < n; j++)
          if (j != i && ((s >> j) & 1))
            chmin(dp[s][i], dp[s ^ (1 << i)][j] + w[j][i]);
  printf("%d\n", dp[(1 << n) - 1][n - 1]);
}
