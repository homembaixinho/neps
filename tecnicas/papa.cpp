// Trabalho do Papa
// https://neps.academy/lesson/177

#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h> 

#define MAXN 1001
#define MAXR 1000001

using namespace std;
using par = pair<int, int>;
using memo = map<par, int>;

struct caixa { int p, r; };
bool operator <(caixa a, caixa b) { return a.r < b.r; }

int n;
caixa cx[MAXN];
memo dp;

int knapsack(int n, int c) {
  if (n == 0 || c == 0 || cx[n].r < 0) return 0;
  if (cx[n].p > c) return knapsack(n-1, c);

  par k = make_pair(n, c);
  memo::iterator it = dp.find(k);

  if (it == dp.end())
    return dp[k] = max(
      knapsack(n-1, c),
      1 + knapsack(n-1, min(c-cx[n].p, cx[n].r))
    );

  return it->second;
}

int main() {
  cin >> n; 
  for (int i = 1; i <= n; ++i) {
    cin >> cx[i].p >> cx[i].r;
    cx[i].r -= cx[i].p;
  }
 
  sort(cx+1, cx+n+1);
  cout << knapsack(n, MAXR) << endl;
}
