#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

void dfs(vector<vector<int>> &adj_list,vector<bool> &visited,int src);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj_list(n+1);
	for (int i = 0; i < m; ++i){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	/*
	cout << "Adj List : \n\n";
	for (auto &i : adj_list){
		for (auto &j: i) cout << j << " ";
		cout << endl;
	}*/

	vector<bool> visited(n+1,false);
	vector<int> ans;
	for (int i = 1; i <= n; ++i){
		if (visited[i] == false){
			dfs(adj_list,visited,i);
			//cout << "island with vertex " << i << endl;
			ans.push_back(i);
		}
	}
	cout << ans.size() - 1 << endl;
	for (int i = 0; i < ans.size()-1; ++i){
		cout << ans[i] << " " << ans[i+1] << endl;;
	}
	return 0;
}

void dfs(vector<vector<int>> &adj_list,vector<bool> &visited,int src){
	if (visited[src] == false){
		visited[src] = true;
		for (int &i : adj_list[src]){
			//printf("visited : %d\n",i);
			dfs(adj_list,visited,i);
		}
	}
}
