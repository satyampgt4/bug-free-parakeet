#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1] = {
    0
  };
  int b[n + 1] = {
    0
  };
  int mav = 0;
  for (int j = 1; j < n + 1; j++) {
    cin >> a[j] >> b[j];
    mav += b[j];
  }

  std::vector < long > dp(mav + 1, INT_MAX);

  dp[0] = 0;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = mav - b[i]; j >= 0; --j) {
      dp[j + b[i]] = min(dp[j + b[i]], dp[j] + a[i]);
    }
  }

  int answer = 0;
  for (int j = 1; j < mav + 1; j++) {
    if (dp[j] <= k) {
      answer = max(answer, j);
    }
  }

  std::cout << answer << std::endl;
  return 0;
}
