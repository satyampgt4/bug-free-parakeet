#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", & n);
  int a[n];
  for (int j = 0; j < n; j++)
    scanf("%d", & a[j]);
  int dp[n];
  dp[0] = 0;
  dp[1] = abs(a[0] - a[1]);
  for (int j = 2; j < n; j++) {
    dp[j] = min(dp[j - 1] + abs(a[j] - a[j - 1]), 
            dp[j - 2] + abs(a[j] - a[j - 2]));
  }
  printf("%d", dp[n - 1]);
  return 0;
}
