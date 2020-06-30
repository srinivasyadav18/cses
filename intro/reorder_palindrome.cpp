#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	unordered_map<char,int> m;
	for (char &c : s) m[c]++;
	
	int count = 0;

	int odd_count = -1;
	char odd_char = -1;

	for (auto &p : m) {
		if (p.second % 2) {
			count++;
			odd_count = p.second;
			odd_char = p.first;	
		}
	}
	if (count > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	string res = "";
	if (count){
		m.erase(odd_char);
		res = string(odd_count,odd_char);
	}
	for (auto &p : m){
		string con = string(p.second/2,p.first);
		res = con + res + con;
	}
	cout << res << endl;
	return 0;
}

