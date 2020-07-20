#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

class Solution{
	int r,c;
	bool ans;
	string ans_string;
	vector<int> start,end;
	vector<vector<char>> dp;
	map<vector<int>,char> directions = {
		{{0,1},'R'},
		{{0,-1},'L'},
		{{1,0},'D'},
		{{-1,0},'U'}
	};
	queue<vector<int>> q;
	map <vector<int>,char>> parent;
	public:
		Solution(int m,int n){
			this->ans = false;
			this->ans_string = "";
			this->r = m;
			this->c = n;
			this->dp = move(vector<vector<char>> (this->r,vector<char> (this->c)));
			this->input();
		}
		void input(){
			for (int i = 0; i < r; ++i){
				for (int j = 0; j < c; ++j){
					cin >> dp[i][j];
					if (dp[i][j] == 'A') this->start = {i,j};
					if (dp[i][j] == 'B') this->end = {i,j};
				}
			}
		}
		void display(){
			for (auto &i : dp){
				for (auto &j : i){
					cout << j << " ";
				}cout << endl;
			}
		}
		bool isValid(const vector<int>& curr){
			int i = curr[0];
			int j = curr[1];
			if (i < 0 || i > r-1 || j < 0 || j > c-1 || dp[i][j] == '#') return false;
			return true;
		}
		void enqueue(const vector<int>& curr){
			for (auto dir : directions){
				vector<int> temp = {curr[0]+dir.first[0],curr[1]+dir.first[1]};;
				if (isValid(temp)) {
					q.push(temp);
					dp[temp[0]][temp[1]] = '#';
					parent[temp] = {curr,dir.second};
				}	
			}
		}
		void solve(){
			q.push(start);
			dp[start[0]][start[1]] = '#';
			parent[start] = {start,'#'};
			while(q.size()){
				auto curr = q.front();
				if (curr == end) {
					ans = true;
					cout << "YES\n";
					get_string();
					return;
				}
				enqueue(curr);
				q.pop();
			}
			cout << "NO\n";
		}
		void get_string(){
			auto p = parent[end];
			while(p.second != '#'){
				ans_string += p.second;
				p = parent[p.first];
			}
			cout << ans_string.length() << endl;
			for (int i = ans_string.length() - 1; i >= 0; --i){
				cout << ans_string[i];
			}
			cout << endl;
		}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m,n;
	cin >> m >> n;
	auto s = Solution(m,n);
	s.solve();
	return 0;
}

