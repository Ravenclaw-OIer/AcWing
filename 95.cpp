// Problem: 递归实现指数型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/94/
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
int n, m;
vector<int> ans;
vector<vector<int> > answers;
void dfs(int dep) {
  if (ans.size() > m || ans.size() + n - dep + 1 < m) return;
  if (dep == n + 1) {
    answers.push_back(ans);
    return;
  }
  dfs(dep + 1);
  ans.push_back(dep);
  dfs(dep + 1);
  ans.pop_back();
}
int main() {
  rd(n); rd(m);
  dfs(1);
  for (int i = answers.size() - 1; i >= 0; i--) {
    rep(j, answers[i].size()) printf("%d ", answers[i][j]);
    puts("");
  }
}
