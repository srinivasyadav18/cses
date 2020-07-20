#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

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

	queue<int> q;
	vector<bool> visited(n+1,false);
	vector<int> parent(n+1,0);

	int src = 1;
	int dest = n;
	int length = 0;
	bool found = false;
	q.push(1);
	visited[1] = true;
	while(q.size()){
		src = q.front();
		for (int i : adj_list[src]){
			if (visited[i] == false) {
				visited[i] = true;
				parent[i] = src;
				if (i == dest) {
					found = true;	
					break;
				}
				q.push(i);
			}
		}
		q.pop();
	}
	if (found == false){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	vector<int> path;
	while(dest != 1){
		path.push_back(dest);
		dest = parent[dest];
	}
	path.push_back(dest);
	reverse(path.begin(),path.end());
	cout << path.size() << endl;
	for (int &i : path) cout << i << " ";
	return 0;
}

