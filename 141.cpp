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
using ull = unsigned long long;
const int base = 13331;
struct Hasher {
  ull h[1000100], p[1000100];
  void initHash(string& s) {
    if (s[0] != '$') s = '$' + s;
    int n = s.length();
    p[0] = 1;
    repn(i, n) {
      h[i] = h[i - 1] * base + (s[i] - 'a' + 1);
      p[i] = p[i - 1] * base;
    }
  }
  ull getRangeHash(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }
} cis, trans;

int main() {
  string str;
  int kase = 0;
  while (cin >> str) {
    if (str == "END") return 0;
    int ans = 0;
    cis.initHash(str);
    auto rts = str;
    reverse(rts.begin(), rts.end());
    trans.initHash(rts);
    int n = str.length() - 1;
  //  cerr << n << endl;
    repn(i, n) {
      // odd-lengthed substrings
      int L = 0, R = min(n - i, i - 1), res = -1;
      while (L <= R) {
        int mid = (L + R) >> 1;
        if (cis.getRangeHash(i - mid, i) ==
            trans.getRangeHash(n + 1 - (i + mid), n + 1 - i)) {
          res = mid;
          L = mid + 1;
        } else {
          R = mid - 1;
        }
      }
      chmax(ans, 2 * res + 1);
      // even-lengthed substrings
      if (i != n) {
        //  cerr << "!!!" << endl;
        L = 0;
        R = min(i - 1, n - i);
        res = -1;
        /*
          abcddcba
             ^
             mid
        */
        while (L <= R) {
          int mid = (L + R) >> 1;
          eprintf("@i = %d, mid = %d, cis hash = %llu", i, mid,
                  cis.getRangeHash(i - mid, i));
          eprintf(", trans hash = %llu (left = %d, right = %d)\n",
                  trans.getRangeHash(n + 1 - (i + mid + 1), n - i),
                  n + 1 - (i + mid + 1), n - i);
          if (cis.getRangeHash(i - mid, i) ==
              trans.getRangeHash(n + 1 - (i + mid + 1), n - i)) {
            res = mid;
            L = mid + 1;
          } else {
            R = mid - 1;
          }
        }
        
        chmax(ans, 2 * (res + 1));
      }
    }
    printf("Case %d: %d\n", ++kase, ans);
  }
}
