#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,k;
  std::cin >>n>>k ;
  int a[n+1] = {0};
  int b[n+1] = {0};
  for (int j = 1; j < n+1; j++) 
    std::cin >>a[j]>>b[j] ;
  long dp[n+1][k+1] ;
  
  
    for(int i=0; i<n+1;++i)
      for(int j=0;j<k+1;++j)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(j>=a[i])
                dp[i][j] = max(dp[i-1][j],b[i]+dp[i-1][j-a[i]]);
            else
                dp[i][j]= dp[i-1][j];
        }


  std::cout <<dp[n][k]  << std::endl;
  return 0;
}
