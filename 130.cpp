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
#define eprintf(...) ;//fprintf(stderr, __VA_ARGS__)
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
const int N = 1000100;
int ans[N], sum[N];
void debug(stack<int> a, stack<int> b) {
  int s = a.size() + b.size();
  eprintf("Content of a: ");
  while (!a.empty()) {
    eprintf("%d ", a.top());
    a.pop();
  }
  eprintf("\n");
  eprintf("Content of b: ");
  while (!b.empty()) {
    eprintf("%d ", b.top());
    b.pop();
  }
  eprintf("\n");
  for (int i = 1; i <= s; i++) eprintf("%d ", sum[i]);
  eprintf("\n");
  for (int i = 1; i <= s; i++) eprintf("%d ", ans[i]);
  eprintf("\n");
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  int x;
  cin >> n;
  stack<int> a, b;
  rep(_, n + 1) ans[_] = -1e9;
  int pos = 0;
  repn(_, n) {
    char op;
    eprintf("AcWing 654: %d> ", _);
    cin >> op;
    switch (op) {
      case 'I':
        cin >> x;
        a.push(x);
        pos++;
        eprintf("pos: %d\n", pos);
        sum[pos] = sum[pos - 1] + x;
        ans[pos] = max(ans[pos - 1], sum[pos]);
        break;
      case 'D':
        if (a.empty()) break;
        a.pop();
        pos--;
        break;
      case 'L':
        if (a.empty()) break;
        x = a.top();
        a.pop();
        pos--;
        b.push(x);
        break;
      case 'R':
        if (b.empty()) break;
        x = b.top();
        b.pop();
        pos++;
        a.push(x);
        sum[pos] = sum[pos - 1] + x;
        ans[pos] = max(ans[pos - 1], sum[pos]);
        break;
      case 'Q':
        int k;
        cin >> k;
        cout << ans[k] << endl;
        break;
      default:
        eprintf("Bad command\n");
    }
    debug(a, b);
  }
}
