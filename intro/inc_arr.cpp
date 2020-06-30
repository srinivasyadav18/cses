#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	vector<ull> arr(n);
	for (ull &i : arr) cin >> i;

	ull turns = 0;
	ull max_so_far = arr[0];

	for (ull i = 0 ; i < n ; ++i){
		if (max_so_far > arr[i]) {
			turns += (max_so_far - arr[i]);
		}
		else max_so_far = arr[i];
	}
	cout << (ull)turns << endl;
	return 0;
}

