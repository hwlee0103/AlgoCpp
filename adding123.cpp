#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int adding123(int n, vector<int> &memo) {
	if (n == 1) return memo[n] = 1;
	else if (n == 2) return memo[n] = 2;
	else if (n == 3) return memo[n] = 4;
	if (memo[n] != 0) return memo[n];
	return memo[n] = adding123(n - 1, memo) + adding123(n - 2, memo) + adding123(n - 3, memo);
}


int main(void) {

	int t;
	cin >> t;

	vector<int> memo;
	memo.resize(11, 0);

	while (t--) {
		int n;
		cin >> n;
		printf("%d\n", adding123(n, memo));
	}

	return 0;
}