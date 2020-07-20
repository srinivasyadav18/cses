#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

void dfs(vector<vector<char>> &dp,int i,int j,int r,int c){
	if (i < 0 || i > r || j < 0 || j > c || dp[i][j] == '#') return;
	dp[i][j] = '#';
	dfs(dp,i+1,j,r,c);
	dfs(dp,i-1,j,r,c);
	dfs(dp,i,j+1,r,c);
	dfs(dp,i,j-1,r,c);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m,n;
	cin >> m >> n;

	vector<vector<char>> dp(m,vector<char>(n));

	for (auto &i : dp)
		for (auto &j : i) cin >> j;
	
	int count = 0;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (dp[i][j] == '.') {
				dfs(dp,i,j,m-1,n-1);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}

