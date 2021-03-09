#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        coin[i] = x;
    }

    //vector<vector<int> > dp;
    //dp.resize(n, vector<int>(k + 1, 0));
    vector<int> dp(k + 1, 0);

    //1차원으로 풀기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0) {
                dp[j] = 0;
                continue;
            }
            if (i == 0) {
                if (j % coin[i] == 0)
                    dp[j] = 1;
                else dp[j] = 0;
            }
            else {
                if (j - coin[i] < 0) continue;
                else if (j - coin[i] == 0) dp[j]++;
                else {
                    dp[j] = dp[j] + dp[j - coin[i]];
                }
            }
        }
    }
    cout << dp[k] << endl;
    return 0;

}