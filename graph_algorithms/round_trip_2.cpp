#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

void dfs(const vector<vector<int>> &adj_list,vector<bool> visited,int dest,int src,vector<int> curr);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj_list(n+1);
	for (int i = 0;i < m; ++i){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	for (int i = 1; i <= n; i++){
		cout << i << " ";
		for (auto j : adj_list[i]) cout << j << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; ++i){
		vector<bool> visited(n+1,false);
		cout << "from " << i << " visited ";
		dfs(adj_list,visited,i,i,vector<int>());
		cout << endl;
	}
	return 0;
}

void dfs(const vector<vector<int>> &adj_list,vector<bool> visited,int dest,int src,vector<int> curr){
	cout << src << " ";
	for (int i : adj_list[src]){
		if (visited[i] == false){
			curr.push_back(i);
			visited[i] = true;
			if (dest == i){
				if (curr.size() >= 4) {
					cout << endl << "found a cycle : ";
					for (int j : curr) cout << j << " ";
				}
			}
			dfs(adj_list,visited,dest,i,curr);
		}
	}
}

