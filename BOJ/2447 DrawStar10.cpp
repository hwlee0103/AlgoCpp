#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dr[3] = { 0, 1, 2 };
int dc[3] = { 0, 1, 2 };

void star10(int n, int r, int c, vector<vector<char> > &stars) {
	if (n == 1) {
		stars[r][c] = '*';
		return;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			star10(n / 3, r + dr[i] * (n / 3), c + dc[j] * (n / 3), stars);
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	vector<vector<char> > stars;
	stars.resize(n + 1, vector<char>(n + 1));

	star10(n, 0, 0, stars);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (stars[i][j] == '\0') printf(" ");
			else printf("%c", stars[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}