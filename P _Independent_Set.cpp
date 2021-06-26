#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 12; 
const long long mod = 1e9 + 7; 
vector<int> graph[maxn];
long long dp[maxn][2];


void dfs(int v, int parent) {
  dp[v][0] = dp[v][1] = 1; 
  for (auto i: graph[v]) {
    if (i != parent) {
      dfs(i, v); 
      (dp[v][1] *= dp[i][0]) %= mod; 
      (dp[v][0] *= (dp[i][1] + dp[i][0])) %= mod; 
    }
  }
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; 
  cin >> n; 
  for (int i = 1; i < n; i++) {
    int v, to; 
    cin >> v >> to;
    graph[v].push_back(to);  
    graph[to].push_back(v); 
  } 
  dfs(1, 0); 
  cout << (dp[1][1] + dp[1][0]) % mod << "\n";
  return 0; 
}
