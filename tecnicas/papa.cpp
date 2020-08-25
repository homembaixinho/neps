// Trabalho do Papa
// https://neps.academy/lesson/177

#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h> 

#define MAXN 1001
#define MAXR 1000001
using namespace std;

int n;
struct caixa { int p, r; };
bool operator <(caixa a, caixa b) { return a.r < b.r; }

caixa cx[MAXN];
map<pair<int, int>, int> memo;
map<pair<int, int>, int>::iterator it;
pair<int, int> k;

int knapsack(int n, int c) {
  if (n == 0 || c == 0 || cx[n].r < 0) return 0;
  if (cx[n].p > c) return knapsack(n-1, c);

  k = make_pair(n, c);
  it = memo.find(k);

  if (it == memo.end())
    return memo[k] = max(
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
