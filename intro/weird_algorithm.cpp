#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int n;
	cin >> n;
	while(n != 1){
		cout << n << " ";
		if (n % 2) {
			n *= 3;
			n++;
		}else n /= 2;
	}
	cout << n ;
	return 0;
}

