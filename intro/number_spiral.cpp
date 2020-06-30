#include <bits/stdc++.h>
#define ull unsigned long long int 
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	while(n--){
		ull i,j;
		cin >> i >> j;

		ull m = max(i,j);

		ull low = m*m - 2*m + 2;
		ull high = m*m;

		if (m % 2 == 0){
			if (i < j) cout << low + i - 1;
			else cout << high - j + 1;
		}
		else{
			if (i > j) cout << low + j - 1;
			else cout << high - i + 1;
		}
		cout << endl;
	}
	return 0;
}

