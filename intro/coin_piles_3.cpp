#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

map<pair<int,int>,bool> dp;


bool recurse(pair<int,int> p){
	if (p.first == 0 && p.second == 0) return true;
	if (p.first < 0 || p.second < 0) return false;
	if (dp.find(p) != dp.end()) return dp[p];
	bool left_ans = recurse(make_pair(p.first - 1,p.second - 2));
	bool right_ans = recurse(make_pair(p.first - 2,p.second -1));
	dp[p] = left_ans || right_ans;
	
	return left_ans || right_ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	recurse(make_pair(1e9,1e9));
	int t;
	cin >> t;
	while(t--){
		pair<int,int> p;
		cin >> p.first >> p.second;

		bool ans = recurse(p);
		if (ans) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}

