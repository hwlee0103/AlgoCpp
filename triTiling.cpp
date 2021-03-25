#include <iostream>
#include <vector>

using namespace std;

int tiling(int n, vector<int> &dp) {
	if (n % 2 != 0) return dp[n] = 0;
	if (n == 2) return dp[n] = 3;
	else if (n == 4) return dp[n] = tiling(n - 2, dp) * 3;
	if (dp[n] != 0) return dp[n];
	return dp[n] = tiling(n - 2, dp) * 3 + tiling(n - 4, dp) * 2 +2;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> dp;
	dp.resize(n + 1, 0);
	
	if (n % 2 != 0) return 0;

	dp[2] = 3;
	
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3 + 2;
		
		if (i == 4) continue;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[n] << endl;

	return 0;
}