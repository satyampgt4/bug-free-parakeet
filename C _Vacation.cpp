#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", & n);
  array<int, 3>dp = {0,0,0};
  
  for (int j = 0; j < n; j++) {
    array<int, 3>input;
    array<int, 3>temp = {INT_MIN,INT_MIN,INT_MIN};
    scanf("%d%d%d", &input[0],&input[1],&input[2]);
    
    for(int i=0; i<3;++i)
      for(int k=0;k<3;++k)
        if(i!=k)
          temp[i] = max(input[i]+dp[k],temp[i]);    
    dp = temp;
  }
  
  int answer =0;
  for(int j=0;j<3;++j)
    answer = max(answer , dp[j]); 
  
  printf("%d", answer);
  return 0;
}
