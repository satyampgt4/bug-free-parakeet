#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dp[n + 1][k + 1];
	for (int i = 0; i <= k; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		long long int sum = 1;
		for (int j = 1; j <= k; j++)
		{
			if (j <= a[i - 1])
			{
				sum += dp[i - 1][j];
				sum %= mod;
				dp[i][j] = sum;
			}
			else {
				sum -= dp[i - 1][j - a[i - 1] - 1];
				sum += dp[i - 1][j];
				sum %= mod;

				dp[i][j] = sum % mod;
			}
		}
	}

	if(dp[n][k]<0) dp[n][k]+=mod;
	cout << dp[n][k] << endl;

}
