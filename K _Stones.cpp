#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector < bool > dp(k + 1);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= a[j] && !dp[i - a[j]])
        dp[i] = true;
    }
  }
  if (dp[k])
    cout << "First";
  else
    cout << "Second";
}
