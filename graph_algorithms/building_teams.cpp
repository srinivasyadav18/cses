#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

void dfs(const vector<vector<int>> &adj_list, vector<bool> &visited, int src,bool id,
vector<int> &ans);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj_list(n+1);
	vector<pair<int,int>> edges;
	for (int i = 0; i < m;++i){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
		edges.push_back(make_pair(u,v));
	}

	vector<bool> visited(n+1,false);
	vector<int> ans(n+1,0);
	for (int i = 1; i <= n; ++i){
		if (visited[i] == false){
			visited[i] = true;
			dfs(adj_list,visited,i,false,ans);
		}
	}
	for (auto &edge : edges){
		if (ans[edge.first] == ans[edge.second]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}
	return 0;
}

void dfs(const vector<vector<int>> &adj_list, vector<bool> &visited, int src,bool id,vector<int> &ans){
	if (id) ans[src] = 2;
	else ans[src] = 1;
	for (int i : adj_list[src]){
		if (visited[i] == false){
			visited[i] = true;
			dfs(adj_list,visited,i,!id,ans);
		}
	}
}
