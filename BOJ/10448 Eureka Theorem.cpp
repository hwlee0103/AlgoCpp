#include <iostream>
#include <vector>
using namespace std;

int func(int now, int sum, int cnt, int k, vector<int> &eurekaNum) {
	if (cnt == 3)
		return (sum == k) ? 1 : 0;

	int ans = 0;
	
	for (int i = 1; i <= 50; ++i) {
		ans = func(i, sum + eurekaNum[i], cnt + 1, k, eurekaNum);
		if (ans == 1) return ans;
	}

	return ans;
}

int main(void) {
	int tc, k;
	cin >> tc;
	vector<int> eurekaNum(51, 0);
	for (int i = 1; i <= 50; ++i) {
		eurekaNum[i] = (i * (i + 1)) / 2;
	}

	for (int i = 0; i < tc; ++i) {
		int ans = 0;
		cin >> k;
		ans = func(1, 0, 0, k, eurekaNum);
		printf("%d\n", ans);
	}

	return 0;
}