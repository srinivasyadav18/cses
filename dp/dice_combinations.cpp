#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

ll mod = 1e9 + 7;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll sum;
	cin >> sum;

	vector<ll> dp(sum+1,0);
	dp[0] = 1;
	for (int i = 1 ; i <= sum ; i++){
		for (int j = 1 ; j <= 6 ; j++){
			if (i -j >= 0) dp[i] += dp[i-j] % mod;
			else break;
		}
	}

	cout << dp[sum] % mod << endl;
	return 0;
}

