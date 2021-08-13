// Problem: 电影
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/105/
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
const int N = 200020;
int a[N], n, m, x[N], y[N];
vector<int> lang;
int query(int x) {
  return lower_bound(lang.begin(), lang.end(), x) - lang.begin();
}
int main() {
  rd(n);
  repn(i, n) {
    rd(a[i]);
    lang.push_back(a[i]);
  }
  rd(m);
  repn(i, m) {
    rd(x[i]);
    lang.push_back(x[i]);
  }
  repn(i, m) {
    rd(y[i]);
    lang.push_back(y[i]);
  }
  // discrete
  sort(lang.begin(), lang.end());
  lang.erase(unique(lang.begin(), lang.end()), lang.end());
  vector<int> speakers(lang.size());
  repn(i, n) {
    int usel = query(a[i]);
    speakers[usel]++; 
  }
  int best_voice = 0, best_subtitle = 0, ans = -1;
  repn(i, m) {
    int X = query(x[i]), Y = query(y[i]);
    if (speakers[X] > best_voice) {
      best_voice = speakers[X];
      best_subtitle = speakers[Y];
      ans = i;
    } else if (speakers[X] == best_voice) {
      if (speakers[Y] > best_subtitle) {
        best_voice = speakers[X];
        best_subtitle = speakers[Y];
        ans = i;
      }
    }
  }
  printf("%d\n", ans);
}
