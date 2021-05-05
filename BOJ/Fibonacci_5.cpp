#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fibo(int n, vector<int>& dp) {
    if (n == 0) return dp[n] = 0;
    if (n == 1) return dp[n] = 1;
    if (dp[n] > -1) return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main(void) {
    int n;
    cin >> n;
    vector<int> dp;
    dp.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) dp[i] = -1;

    cout << fibo(n, dp) << endl;

    return 0;
}