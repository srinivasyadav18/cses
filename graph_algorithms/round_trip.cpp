#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

const int mod_int = 1e9 + 7;
const ll mod_ll = 1e9 + 7;

using namespace std;

bool bfs(const vector<vector<int>> &adj_list,
		 vector<bool> &visited,
		 queue<int> &q)
{
	int src = q.front();
	int length = 0;
	bool first = true;
	cout << "front = " << q.front() << endl;
	vector<int> parent(adj_list.size());

	while(!q.empty()){
		int front = q.front();
		if (!first && front == src){
			if (length > 2) {
				int temp = src;
				for (int i : parent) cout << i << " ";
				cout << endl;
				/*while(parent[src] != src){
					cout << src << " ";
					src = parent[src];
				}
				cout << src << endl;
				*/
				cout << "src found at " << length << endl;
				return true;
			}
			else return false;
		}
		first = false;
		for (int i : adj_list[front]) {
			if (visited[i] == false) {
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
		length++;
		q.pop();
	}		
	return false;
}
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

	for (int i = 1; i <= n; ++i){
		vector<bool> visited(n+1,false);
		queue<int> q;
		q.push(i);
		bool ans = bfs(adj_list,visited,q);
	}
	return 0;
}

