#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

bool ans = false;
map<pair<int,int>,char> directions;

void enqueue(queue<pair<int,int>> &q,vector<vector<char>> &dp,pair<int,int> curr_pair);
bool isValid(queue<pair<int,int>> &q,vector<vector<char>> &dp,pair<int,int> curr_pair){
	int i = curr_pair.first;
	int j = curr_pair.second;
	if (i < 0 || i > dp.size() - 1 || j < 0 || j > dp[0].size() - 1 || dp[i][j] == '#')
		return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	directions.insert(make_pair(0,1),'R');
	directions.insert(make_pair(0,-1),'L');
	directions.insert(make_pair(1,0),'U');
	directions.insert(make_pair(-1,0),'D');
	int m,n;
	cin >> m >> n;

	vector<vector<char>> dp(m,vector<char>(n));

	for (auto &i : dp)
		for (auto &j : i) cin >> j;

	pair<int,int> start,end;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (dp[i][j] == 'A') start = make_pair(i,j);
			if (dp[i][j] == 'B') end = make_pair(i,j);
			cout << dp[i][j] << " ";
		}cout << endl;
	}

	cout << "start = " << start.first << " " << start.second << endl;
	cout << "end = " << end.first << " " << end.second << endl;
	queue<pair<int,int>> q;
	unordered_map <pair<int,int>,char>> pre_map;

	q.push(start);
/*	while(!q.empty()){
		if (q.front() == end) break;
		auto curr = q.front();
		if (dp[curr.first][curr.second] != '#'){
			enqueue(q,dp,curr);
			printf("visited %d %d \n",i,j);
			dp[curr.first][curr.second] = '#';
			q.pop();
		}
	}
	return 0;
*/
}
/*
void enqueue(queue<pair<int,int>> &q,vector<vector<char>> &dp,pair<int,int> curr_pair){
	for (auto i : directions) {
		if (isValid(q,dp,curr_pair+i)){
			q.push(curr_pair+i,directions[i]);
		}
	}	
}*/
