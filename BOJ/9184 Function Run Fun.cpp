#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101][101][101];
int w(int a, int b, int c) {
	int aidx = a + 50, bidx = b + 50, cidx = c + 50;
	if (a <= 0 || b <= 0 || c <= 0) {
		return dp[aidx][bidx][cidx] = 1;
	}
	else if (dp[aidx][bidx][cidx] != 0) {
		return dp[aidx][bidx][cidx];
	}
	else if (a > 20 || b > 20 || c > 20) {
		return dp[aidx][bidx][cidx] = w(20, 20, 20);
	}
	else if (a < b && b < c) {
		return dp[aidx][bidx][cidx] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return dp[aidx][bidx][cidx] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main(void) {
	//범위가 [-50, 50]이므로 인덱스 중요!
	//인덱스는 +50 해서 계산하자.
	int a, b, c;
	while (1) {
		scanf_s("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w("<<a<<", "<<b<<", "<<c<<") = "<< w(a, b, c) << "\n";
	}
	return 0;
}