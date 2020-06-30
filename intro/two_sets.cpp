#include <bits/stdc++.h>

#define ull long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	ull sum = (ull)((n*n + n)/2);

	if (sum % 2) {
		cout << "NO" << endl;
		return 0;
	}

	sum /= 2;
	cout << "YES" << endl;
	vector<int> v1,v2;
	while(n){
		if (sum - n >= 0) {
			sum -= n;
			v1.push_back(n);
		}else{
			v2.push_back(n);
		}
		n--;
	}
	cout << v1.size() << endl;;
	for (auto &i : v1) cout << i << " ";
	cout << endl;
	cout << v2.size() << endl;
	for (auto &i : v2) cout << i << " ";
	return 0;
}

