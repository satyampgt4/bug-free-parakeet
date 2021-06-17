#include <bits/stdc++.h>
using namespace std;

const int N = 401;

long long INF = 1e18;

long long dp[N][N]; 
long long siz[N][N]; 

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		siz[i][i] = a[i];
		dp[i][i] = 0;
	}

	// order of evaluation
	for(int width = 2; width <= n; width++){
		for(int l = 0; l<=n-width ; l++ ){
		    int r=l+width-1;
			siz[l][r] = a[l] + siz[l+1][r];
			dp[l][r] = INF;
			for(int x = l; x < r; x++){
				dp[l][r] = min(dp[l][r], dp[l][x] + dp[x+1][r] + siz[l][r]);
			}
		}
	}

	cout << dp[0][n-1];

}
