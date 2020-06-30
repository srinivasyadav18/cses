#include <bits/stdc++.h>
 
#define ull unsigned long long
#define ll long long int
 
ll mod = 1e9 + 7;
 
using namespace std;

ll dp[1000001];
ll coins[100];
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
 
	ll n,sum;
	scanf("%lld %lld",&n,&sum);

	for(int i = 0 ; i < n ; ++i){
		scanf("%lld",&coins[i]);
	}

	dp[0] = 1;

	for (ll i = 1 ; i <= sum ; i++){
		for (ll j = 0 ; j < n ; ++j){
			if (i >= coins[j]) dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
		}
	}

	printf("%lld",dp[sum]);
}
