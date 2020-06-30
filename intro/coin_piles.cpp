#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

vector<vector<bool>> dp(1e9,vector<bool> (1e9,false));

void solve(){
	int a,b;
	cin >> a >> b;

	if (dp[a][b]) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0][0] = true;

	cout << "starting ...\n";		
	for (int i = 1 ; i <= 1e9; ++i){
		cout << '.';
		for (int j = 1 ; j <= 1e9; ++j){
			if (i >= 2 && j >= 1 && dp[i - 2][j-1]) {
				dp[i][j] = true;
				continue;
			}
			if (i >= 1 && j >= 2 && dp[i - 1][j-2]) {
				dp[i][j] = true;
			}
		}
	}
	cout << " dp created ";
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

