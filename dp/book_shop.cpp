#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	cin >> n >> x;

	vector<int> books(n),pages(n);
	for (int &i : books) cin >> i;
	for (int &i : pages) cin >> i;

	vector<vector<int>> dp(n,vector<int>(x+1,0));
	for (int i=books[0]; i<x+1 ; ++i) dp[0][i] = pages[0];

	for (int i = 1; i < n; ++i){
		for (int j = 1; j < x + 1 ; ++j){
			if (j >= books[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-books[i]] + pages[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n-1][x];
	return 0;
}

