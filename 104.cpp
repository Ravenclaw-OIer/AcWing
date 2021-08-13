// Problem: 最佳牛围栏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/104/
// Written by RavenclawOIer on 08-06-2021

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
int n, k;
const int N = 100010;
double a[N], b[N], pre[N];
int main() {
  rd(n);
  rd(k);
  repn(i, n) rd(a[i]);
  double eps = 1e-5;
  double L = -1e6, R = 1e6;
  while (R - L > eps) {
    double mid = (L + R) / 2;
    repn(i, n) b[i] = a[i] - mid;
    repn(i, n) pre[i] = pre[i - 1] + b[i];
    double cur_min = 1e10, ans = -1e10;
    for (int i = k; i <= n; i++) {
      chmin(cur_min, pre[i - k]);
      chmax(ans, pre[i] - cur_min);
    }
    if (ans >= 0)
      L = mid;
    else
      R = mid;
  }
  cout << (int)(R * 1000) << endl;
}
