#include <iostream>
using namespace std;

int func(int n) {
	if (n < 100) return n;
	
	int cnt = 99;
	if (n == 1000) n = 999;

	for (int i = 100; i <= n; ++i) {
		int diff1 = (i / 100) % 10 - (i / 10) % 10;
		int diff2 = (i / 10) % 10 - i % 10;
		if (diff1 == diff2) cnt++;
	}
	
	return cnt;
}

int main(void) {
	int n;
	cin >> n;

	printf("%d\n", func(n));

	return 0;
}