#include <bits/stdc++.h>

#define ull unsigned long long
#define lli long long int

using namespace std;
const unsigned int mod = 1e9 + 7;
lli power(lli a, lli b){
	lli result = 1;
	while(b > 0){
		if (b % 2) result = (result * a) % mod;

		a = ( a * a ) % mod;
		b /= 2;
	}
	return result;
}
		
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	lli n;
	cin >> n;
	cout << power(2,n);
	return 0;
}

