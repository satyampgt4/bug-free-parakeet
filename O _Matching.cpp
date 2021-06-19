#include <bits/stdc++.h>
using namespace std;

int f(int i) {
    int x = 0;
    while(i>0) {
        if(i&1) ++x;
        i >>= 1;
    }
    return x;
}

int main() {
	int n; 
  cin >> n; 
  int mod = (int)(1e9+7);
  
  vector<vector<int>> a(n,vector<int>(n)); 
  
  for(int i=0;i < n;++i) 
    for(int j=0;j < n;++j) 
      cin >> a[i][j];
  
    vector<int> dp(1<<n);
    dp[0] = 1;
    cout << endl;
    for(int i=0;i < (1<<n);++i) {
        int mn = f(i);
        for(int bit=0;bit < n;++bit) {
            if((i&(1<<bit)) == 0 && a[mn][bit]) {
                (dp[i+(1<<bit)] += dp[i]) %= mod;
            }
        }
    }
   
    cout << dp.back() << endl;
}
