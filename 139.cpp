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
const int mod = 99991, N = 100010;
int n;
struct Snowflake {
  int a[7];
  int getHash() const {
    LL sum = 0, prod = 1;
    repn(i, 6) sum = (sum + a[i]) % mod;
    repn(i, 6) prod = (prod * a[i]) % mod;
    return (sum + prod) % mod;
  }
  bool operator==(const Snowflake& b) const {
    repn(i, 6) {    // start checking a from id i
      repn(j, 6) {  // start checking b from id j
        bool eq = true;
        rep(k, 6) if (a[(i + k) % 6 + 1] != b.a[(j + k) % 6 + 1]) eq = false;
        if (eq) return true;
        eq = true;
        rep(k, 6) if (a[(i + k) % 6 + 1] != b.a[(j - k + 6) % 6 + 1]) eq = false;
        if (eq) return true;
      }
    }
    return false;
  }
};
vector<Snowflake> hashTable[N];
bool insert(const Snowflake& s) {
  int h = s.getHash();
//  eprintf("Hash is %d\n", h);
  for (auto r : hashTable[h]) {
    if (r == s) return true;  // exists;
  }
  hashTable[h].push_back(s);
  return false;
}
int main() {
  rd(n);
  repn(i, n) {
    Snowflake s;
    repn(j, 6) rd(s.a[j]);
    if (insert(s)) {
      puts("Twin snowflakes found.");
      return 0;
    }
  }
  puts("No two snowflakes are alike.");
}
