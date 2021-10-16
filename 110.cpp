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
namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}
char pbuf[1 << 20], *pp = pbuf;
inline void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) push(sta[--top] + '0');
}
}  // namespace
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
const int N = 250005;
int a[N], tmp[N];
void mergeSort(int l, int r, LL& ans) {
  if (r - l <= 1) return;
  int mid = (l + r) >> 1;
  mergeSort(l, mid, ans);
  mergeSort(mid, r, ans);
  int L = l, M = mid, cur = l;
  while (cur < r) {
    if (L >= mid || (M < r && a[L] > a[M])) {
      tmp[cur++] = a[M++];
      ans += (mid - L);
    } else {
      tmp[cur++] = a[L++];
    }
  }
  for (int i = l; i < r; i++) a[i] = tmp[i];
}
int main() {
  int n;
  while (n = IO::rd()) {
    int id = 0;
    repn(i, n*n) tmp[i] = 0;
    repn(i, n * n) {
      int x;
      x = IO::rd();
      if (x) a[++id] = x;
    } 
    LL ans1 = 0;
    repn(i, n*n) tmp[i] = 0;
    mergeSort(1, n * n, ans1);
    id = 0;
    repn(i, n * n) {
      int x;
      x = IO::rd();
      if (x) a[++id] = x;
    } 
    LL ans2 = 0;
    mergeSort(1, n * n, ans2);
    cout << (((ans1 - ans2) & 1) ? "NIE" : "TAK") << endl;
  }
}
