#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
using namespace std;
ll mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<char>> grid(n,vector<char> (n));
	for (auto &i : grid)
		for (auto &j : i) cin >> j;
	
	vector<vector<ll>> dp(n,vector<ll> (n,0));
	for (int i = 0 ; i < n ; i++){
		if (grid[i][0] == '*') break;
		else dp[i][0] = 1;
	}

	for (int i = 0 ; i < n ; i++){
		if (grid[0][i] == '*') break;
		else dp[0][i] = 1;
	}
	
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < n; ++j){
			if (grid[i][j] != '*') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
		}
	}
	/*
	for (auto &i : dp){
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
	*/
	cout << dp[n-1][n-1] << endl;
	return 0;
}

