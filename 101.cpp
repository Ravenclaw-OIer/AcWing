// Problem: 激光炸弹
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/101/
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
const int MAXN = 5050;
int n, R;
int S[MAXN][MAXN];
int main() {
  rd(n); rd(R);
  int N = R, M = R;
  repn(i, n) {
    int x, y, w;
    rd(x);
    rd(y);
    x++;
    y++;
    rd(w);
    chmax(N, x); chmax(M, y);
    S[x][y] += w;
  }
  repn(i, N)
    repn(j, M)   
      S[i][j] = S[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
 //  repn(i, N) {repn(j, M) cerr << S[i][j] << ' '; cerr << endl; }
  int ans = 0;
  for (int i = R; i <= N; i++) for (int j = R; j <= M; j++){
 //   eprintf("(%d, %d): %d\n", i, j, S[i][j]);
    chmax(ans, S[i][j] - S[i - R][j] - S[i][j - R] +
                   S[i - R][j - R]);
  }
  cout << ans << endl;
}
