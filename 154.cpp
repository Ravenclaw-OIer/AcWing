/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


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
int n, m;
const int N = 1010;
int a[N][N], s[N][N];
char c[N][N];
void parseInput() {
  cin >> n >> m;
  repn(i, n) repn(j, m) {
    cin >> c[i][j];
    if (c[i][j] == 'F') {
      s[i][j] = a[i][j] = 1;
    }
  }
  
 // cerr << "Input done!" << endl;
  repn(j, m)
    for (int i = n; i >= 1; i--)
      if (a[i][j]) s[i][j] += s[i + 1][j];
 // repn(i, n) { repn(j, m) cerr << s[i][j] << ' ';  cerr << endl;}
}
LL solve(int i) {
 // cerr << "Solving for " << i << endl;
  stack<pii> st;
  LL ans = 0;
  repn(j, m + 1) {
  //  cerr << j << endl;
    if (!st.empty() && s[i][j] > st.top().first) {
      st.push(make_pair(s[i][j], 1));
    } else {
      int w = 0;
      while (!st.empty() && s[i][j] < st.top().first) {
        w += st.top().second;
        chmax(ans, 1LL * w * st.top().first);
        st.pop();
      }
      // push the new big rectangle in
      st.push(make_pair(s[i][j], w + 1));
    }
  }
  return ans;
}
int main() {
  parseInput();
  LL ans = 0;
  repn(i, n) chmax(ans, solve(i));
  printf("%lld\n", ans * 3);
}
