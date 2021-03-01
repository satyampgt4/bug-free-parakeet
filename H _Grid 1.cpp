#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main() {
  int x, y;
  cin >> x >> y;
  dp[0][0] = 1;
  string s[x];
  
  for(int j=0 ;j<x;++j)
  {
      cin>>s[j];
  }

  

  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      if(s[i][j] =='#')
      continue;
      if(s[i][j-1]=='.'){
          dp[i][j] = (dp[i][j]+dp[i][j-1])%1000000007;
      }
      if(s[i-1][j]=='.'){
          dp[i][j] = (dp[i][j]+dp[i-1][j])%1000000007;
      }
    }
  }

  cout << dp[x-1][y-1];
  return 0;
}
