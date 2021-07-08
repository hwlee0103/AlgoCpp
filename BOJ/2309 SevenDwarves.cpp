#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int dwarves[9];
	int sum = 0;

	for (int i = 0; i < 9; ++i) {
		cin >> dwarves[i];
		sum += dwarves[i];
	}
	sort(dwarves, dwarves + 9);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i == j)continue;
			if (sum - (dwarves[i] + dwarves[j]) == 100) {
				for (int k = 0; k < 9; ++k) {
					if (k == i || k == j) continue;
					cout << dwarves[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}