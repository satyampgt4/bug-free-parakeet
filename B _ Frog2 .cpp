#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  scanf("%d%d", & n, &k);
  int a[n];
  for (int j = 0; j < n; j++)
    scanf("%d", & a[j]);
  int dp[n];
  dp[0] = 0;

  for (int j = 1; j < n; j++) {
     dp[j] =INT_MAX;
     int x = min(j,k);
    for (int l = 1; l <=x; l++) {
        dp[j] = min(dp[j], dp[j - l] + abs(a[j] - a[j - l]));
    }
  }
  printf("%d", dp[n - 1]);
  return 0;
}
