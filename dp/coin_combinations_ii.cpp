#include <bits/stdc++.h>

#define ll unsigned long long

ll mod = 1e9 + 7;

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,x;
	cin >> n >> x;

	vector<ll> coins(n);
	for (auto &i : coins) cin >> i;

	vector<ll> dp(x+1,0);
	dp[0] = 1;

	int count = 0;
	for (ll i = 1 ; i < x + 1 ; i++){
		count = 0;
		for (auto &coin : coins){
			if (i >= coin && dp[i-coin]) count++;
		}
		dp[i] = count;
	}

	cout << dp[x] << endl;
	return 0;
}

