#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	auto l = make_pair(1,2);
	auto r = make_pair(2,1);
	auto z = make_pair(0,0);
	while(n--){
		pair<int,int> p;
		cin >> p.first >> p.second;

		if (p.first/3 == p.second/3){
			p.first = p.first % 3;
			p.second = p.second % 3;
			if (p == l || p == r || p == z) {
				cout << "YES" << endl;
				continue;
			}
		}
		cout << "NO" << endl;
	}

	return 0;
}

