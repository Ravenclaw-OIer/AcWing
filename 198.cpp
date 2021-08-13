// Problem: 质数距离
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/198/
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
const int N = 70010;
bool c[N];
vector<LL> primes;
void sieve() {
  memset(c, 0, sizeof(c));
  for (int i = 2; i <= 70000; i++) {
    if (c[i]) continue;
    primes.push_back(i);
    for (int j = i; j <= 70000 / i; j++) c[i * j] = 1;
  }
}
bool pr[1000100];
int main() {
  LL L, R;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  while (scanf("%lld%lld", &L, &R) == 2) {
    if (L == 1) L = 2;
    rep(i, R - L + 1) pr[i] = 1;
    for (auto x : primes) {
      if (x > sqrt(R)) break;
      //   eprintf("prime %lld\n", x);
      for (int i = ceil(L / (double)x); i <= R / x; i++) {
        if (i != 1) {
          pr[i * x - L] = 0;
          //       eprintf("i = %d res = %lld\n", i, i * x - L);
        }
      }
    }
    vector<LL> p;
    for (int i = 0; i < R - L + 1; i++)
      if (pr[i]) p.push_back(i + L);
    //  for (auto x : p) eprintf("%lld ", x);
    //  eprintf("\n");
    LL min_dist = INF, max_dist = -INF;
    pair<LL, LL> min_pair, max_pair;
    if (p.size() < 2) {
      puts("There are no adjacent primes.");
      continue;
    }
    for (int i = 0; i < p.size() - 1; i++) {
      if (p[i + 1] - p[i] < min_dist) {
        min_dist = p[i + 1] - p[i];
        min_pair = make_pair(p[i], p[i + 1]);
      }
      if (p[i + 1] - p[i] > max_dist) {
        max_dist = p[i + 1] - p[i];
        max_pair = make_pair(p[i], p[i + 1]);
      }
    }
    printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
           min_pair.first, min_pair.second, max_pair.first, max_pair.second);
  }
}
