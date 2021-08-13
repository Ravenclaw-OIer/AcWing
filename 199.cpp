// Problem: 阶乘分解
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/199/
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
const int N = 2000000;
bool c[N + 10];
vector<LL> prime;
void sieve() {
  for (int i = 2; i <= N; i++) {
    if (c[i]) continue;
    prime.push_back(i);
    for (int j = i; j <= N / i; j++) c[i * j] = true;
  }
}
int main() {
  LL x;
  rd(x);
  sieve();
  for (auto p: prime) {
    int cnt = 0;
    LL P = p;
    while (true) {
      if (P > x) break;
      cnt += (x / P);
      P *= p; 
    }
    if (cnt == 0) break;
    printf("%lld %d\n", p, cnt);
  }
}
