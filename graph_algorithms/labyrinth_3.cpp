#include <bits/stdc++.h>
#include <unistd.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

int m = 0,n = 0;
bool ans = false;
string ans_string;
vector<string> dp;
map<array<int,2>,char> directions = {
	{{1,0},'D'},
	{{-1,0},'U'},
	{{0,1},'R'},
	{{0,-1},'L'}
};

map<char,array<int,2>> rev_directions = {
	{'U',{1,0}},
	{'D',{-1,0}},
	{'L',{0,1}},
	{'R',{0,-1}}
};

bool isValid(const array<int,2>& a){
	if (a[0] < 0 || a[0] > m-1 || a[1] < 0 || a[1] > n-1 || dp[a[0]][a[1]] != '.')
		return false;
	return true;
}

array<int,2> add(const array<int,2>& a,const array<int,2> &b){
	array<int,2> ret;
	ret[0] = a[0] + b[0];
	ret[1] = a[1] + b[1];
	return ret;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	dp = vector<string> (m);
	vector<string> parent(m,string(n,'.'));
	for (string &i : dp) cin >> i;

	array<int,2> start,end;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j <n; ++j){
			if (dp[i][j] == 'A') {
				start = {i,j};
				dp[i][j] = '.';
			}
			if (dp[i][j] == 'B') {
				end = {i,j};
				dp[i][j] = '.';
			}
		}
	}	

	queue<array<int,2>> q;
	q.push(start);

	while(!q.empty()){
		auto front = q.front();
		if (front == end){
			ans = true;
			break;
		}
		for (auto dir : directions){
			array<int,2> temp = add(dir.first,front);
			if (isValid(temp)){
				q.push(temp);
				parent[temp[0]][temp[1]] = dir.second;
			}
		}
		dp[front[0]][front[1]] = '#';
		q.pop();
	}

	if (ans){
		cout << "YES\n";
		auto temp = end;
		while(temp != start){
			int i = temp[0],j = temp[1];
			char c = parent[i][j];
			ans_string += c;
			temp = add(rev_directions[c],temp);	
		}
		cout << ans_string.length() << endl;
		cout << ans_string << endl;
	}

	else 
		cout << "NO\n";
	return 0;
}

