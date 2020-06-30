#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;

	int n = input.size();
	int streak = 1;
	int best_streak = 1;
	for (int i = 0 ; i < n - 1 ; ++i){
		if (input[i] == input[i+1]) streak++;
		else streak = 1;
		best_streak = max(streak,best_streak);
	}
	cout << best_streak << endl;
	return 0;
}

