// Problem: 64位整数乘法
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/92/
// Written by RavenclawOIer on 07-21-2021

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

int main() {
  long long a, b, p, ans = 0;
  rd(a); rd(b); rd(p);
  for (; b; b >>= 1) {
    if (b & 1) ans = (ans + a) % p;
    a = a * 2 % p;
  }
  cout << ans << endl;
}
