/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
// Problem: 占卜DIY
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/119/
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
int life = 4;

struct Card {
  int num;
  bool flipped;
  Card(int x, bool f = false) {
    num = x;
    flipped = f;
  }
  bool operator==(const int y) const { return num == y; }
};
deque<Card> a[14];
int main() {
  repn(i, 13) {
    rep(j, 4) {
      char c;
      cin >> c;
      int x = -1;
      if (c == 'A')
        x = 1;
      else if (c == 'J')
        x = 11;
      else if (c == 'Q')
        x = 12;
      else if (c == 'K')
        x = 13;
      else if (c == '0')
        x = 10;
      else
        x = c - '0';
      a[i].push_back(Card(x));
    }
  }
  while (true) {
    if (life == 0) break;
    int cur = 13;
    auto card = a[cur].front();
    a[cur].pop_front();
    while (card.num != 13) {
      cur = card.num;
      a[cur].push_front(Card(card.num, true));
      card = a[cur].back();
      a[cur].pop_back();
    }
    life--;
  }
  vector<int> cnt(16);
  int ans = 0;
  repn(i, 13) while (!a[i].empty()) {
    auto x = a[i].front();
    a[i].pop_front();
    if (x.flipped) cnt[x.num]++;
  }
  repn(i, 13) if (cnt[i] == 4) ans++;
  cout << ans << endl;
}
