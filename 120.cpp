// Problem: 分形
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/120/
// Written by RavenclawOIer on 08-13-2021

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
int n;
int power[10];
char canvas[2500][2500];
void solve(int n, int x, int y) {
//  eprintf("solve(%d, %d, %d)\n", n, x, y);
  if (n == 1) {
    canvas[x][y] = 'X';
    return;
  }
  int offset = power[n - 2];
  solve(n - 1, x, y);
  solve(n - 1, x + 2 * offset, y);
  solve(n - 1, x, y + 2 * offset);
  solve(n - 1, x + offset, y + offset);
  solve(n - 1, x + 2 * offset, y + 2 * offset);
}
int main() {
  int x = 1;
  rep(i, 9) {
    power[i] = x;
    x *= 3;
  }
  while (rd(n) != -1) {
    // calculate the size of the output
  //  cerr << n << ' ' << power[n] << endl;
    repn(i, power[n - 1])
      repn(j, power[n - 1])
        canvas[i][j] = ' ';
    solve(n, 1, 1);
    repn(i, power[n - 1]) {
      repn(j, power[n - 1])
        putchar(canvas[i][j]);
      puts("");
    }
    puts("-");
  }
}
