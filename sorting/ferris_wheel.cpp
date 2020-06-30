#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	cin >> n >> x;

	vector<int> weights(n);
	for(int &i : weights) cin >> i;

	sort(weights.begin(),weights.end());

	int l = 0;
	int r = n - 1;

	int count = 0;

	/*
	cout << endl;
	for (int &i : weights) cout << i << " ";
	cout << endl;*/
	while(l <= r){
		if (weights[r] + weights[r-1] <= x){
			r -= 2;
			count++;
			continue;
		}
		if (weights[r] + weights[l] <= x){
			r--;
			l++;
			count++;
			continue;
		}
		count++;
		r--;
	}
	
	cout << count << endl;	
	return 0;
}

