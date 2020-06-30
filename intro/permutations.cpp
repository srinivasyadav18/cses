#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if ( n == 1) {
		cout << "1";
		return 0;
	}
	if (n == 4){
		cout << "2 4 1 3" << endl;
		return 0;
	}
	if ( n < 5 ) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	int start = n;
	if (n % 2) start = n - 1;

	for (int i = start ; i >= 2 ; i -= 2){
		cout << i << " ";
	}

	start = n;
	if (n % 2 == 0) start = n -1;
	for (int i = start ; i >= 1 ; i -= 2){
		cout << i << " ";
	}
	
}

