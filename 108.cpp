// Problem: 动态中位数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/108/
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

int main() {
  int T;
  rd(T);
  while (T--) {
    int kase, n;
    rd(kase);
    rd(n);
    printf("%d %d\n", kase, (n + 1) / 2);
    eprintf("Entering case %d\n", kase);
  priority_queue<int> q1, reimu;
priority_queue<int, vector<int>, greater<int> > q2, marisa;
    int output_cnt = 0;
    repn(i, n) {
      int u;
      rd(u);
      if (q2.empty()) {
        q2.push(u);
      } else {
        if (u > q2.top()) {
          q2.push(u);
        } else {
          q1.push(u);
        }
        // maintain
        while (q1.size() > q2.size()) {
          q2.push(q1.top());
          q1.pop();
        }
        while (q1.size() + 1 < q2.size()) {
          q1.push(q2.top());
          q2.pop();
        }
      }
      if (i & 1) {
        output_cnt++;
        printf("%d", q2.top());
        if (output_cnt % 10 == 0)
          printf("\n");
        else
          printf(" ");
      }
    }
    if (output_cnt % 10 != 0) puts("");
  }
}
