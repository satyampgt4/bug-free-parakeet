#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
vector<vector<long long>> memo;
vector<vector<bool>> calculated;

long long f(int i, int j) {
	if (calculated[i][j]) return memo[i][j];
	calculated[i][j] = true;
	if (i == j)return memo[i][j] = a[i];
	return memo[i][j] = max(a[i] - f(i + 1, j), a[j] - f(i, j - 1));
}

int main()
{
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	memo.resize(n + 1, vector<long long>(n + 1));
	calculated.resize(n + 1, vector<bool>(n + 1));
	cout << f(1, n) << endl;
	return 0;
}
