#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
bool isPrime[1000001];

int main(void) {
	int m, n;
	cin >> m >> n;

	isPrime[1] = true;

	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			isPrime[j] = true;
		}
	}

	for (int i = m; i <= n; ++i) {
		if (!isPrime[i]) cout << i << '\n'; // endl 대신 \n 사용해야 시간초과가 나지 않는다.
	}

	return 0;
}