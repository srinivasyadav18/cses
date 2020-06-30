#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,sum;
	cin >> n >> sum;

	vector<int> coins(n,0);
	for (int &i : coins) cin >> i;
	sort(coins.begin(),coins.end());

	vector<int> dp(sum+1,0);

	for (int i = 1 ; i < sum + 1 ; ++i){
		int s = 0;
		int min_coins = INT_MAX;
		for (int &coin : coins) {
			if (i - coin >= 0 && dp[i-coin] != INT_MAX){
				min_coins = min(min_coins,dp[i - coin]);
			}
		}
		if (min_coins != INT_MAX)
			dp[i] = min_coins + 1;
		else dp[i] = INT_MAX;
	}
	/*
	cout << endl;

	for (int &i : dp) cout << i << " ";
	cout << endl;*/
	if (dp[sum] != INT_MAX)
		cout << dp[sum] << endl;
	else cout << -1 << endl;
	return 0;
}

