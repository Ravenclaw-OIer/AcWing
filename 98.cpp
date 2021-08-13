// Problem: 奇怪的汉诺塔
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/98/
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
int dp[20], d[20];
int main() {
  dp[1] = 1;
  d[1] = 1;
  for (int i = 2; i <= 12; i++) d[i] = 2 * d[i - 1] + 1;
  cout << 1 << endl;
  for (int n = 2; n <= 12; n++) {
    dp[n] = INF;
    for (int i = 1; i < n; i++) {
      chmin(dp[n], 2 * dp[i] + d[n - i]);
    }
    cout << dp[n] << endl;
  }
}
