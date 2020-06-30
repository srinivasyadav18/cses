#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n,0);
	for (int &i : nums) cin >> i;

	sort(nums.begin(),nums.end());
	ll sum1 = 0;
	ll sum2 = 0;
	for (auto i : nums) cout << i << " ";
	cout << endl;
	int i = n-1;
	while(i >= 0){
		if (sum1 < sum2) sum1 += nums[i];
		else sum2 += nums[i];
		i--;
	}
	cout << abs(sum1 - sum2);

	return 0;
}

