#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	int e, s, m;
	cin >> e >> s >> m;
	// 1 <= e <= 15, 1 <= s <= 28, 1 <= m <= 19
	// 0 <= e <= 14, 0 <= s <= 27, 0 <= m <= 18
	e -= 1;
	s -= 1;
	m -= 1;

	int year = 0;
	while (1) {
		if (year % 15 == e && year % 28 == s && year % 19 == m) break;
		else year++;
	}
	cout << year + 1 << endl;

	return 0;
}