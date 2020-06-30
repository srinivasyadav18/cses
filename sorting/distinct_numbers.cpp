#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set <int> s;

	int num;
	for (int i = 0 ; i < n ; i++){
		cin >> num;
		if (s.find(num) == s.end())
		s.insert(num);
	}

	cout << s.size() << endl;
	return 0;
}

