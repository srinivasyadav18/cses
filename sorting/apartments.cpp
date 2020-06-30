#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m,k;

	cin >> n >> m >> k ;

	vector<int> req(n),buildings(m);

	for (int &i : req) cin >> i;
	for (int &i : buildings) cin >> i;

	sort(req.begin(),req.end());
	sort(buildings.begin(),buildings.end());

	int i = 0; // req ptr
	int j = 0; // building ptr
	int count = 0; // no of buildings sold

	while(i < n && j < m){
		if (req[i] - k > buildings[j]) {
			j++;
			continue;
		}
		if (req[i] + k < buildings[j]){
			i++;
			continue;
		}
		i++;j++;count++;
	}
	cout << count << endl;
	return 0;
}

