#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> dp(n+1,0);

	int m = INT_MAX;
	for (int i = 1 ; i < n+1 ; ++i){
		m = INT_MAX;
		//cout << "i = " << i << " ";
		int num = i;
		while(num > 0){
			int digit = num % 10;
			//cout << "digit = " << digit << " ";
			if (digit)
				m = min(dp[i-digit],m);
			num /= 10;
		}
		dp[i] = m + 1;
	}

	cout << dp[n] << endl;
	return 0;
}

