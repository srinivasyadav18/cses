#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long n;
	cin >> n;

	unsigned long long req = (n * (n+1) ) / 2;
	unsigned long long sum = 0;

	vector<int> nums(n - 1);

	for (int &i : nums) {
		cin >> i;
		sum += i;
	}
	unsigned long long ans = req - sum;
	cout << ans;
	return 0;
}

