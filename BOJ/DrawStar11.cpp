#include <iostream>
#include <vector>

using namespace std;

int dr[3] = { 0, 1, 2 };
int dc[5] = { -2, -1, 0, 1, 2 };

void drawingStars(int now, int r, int c, vector<vector<char> > &stars) {
	if (now == 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (i == 0 && j != 2) continue;
				else if (i == 1 && (j != 1 && j != 3)) continue;
				stars[r + dr[i]][c + dc[j]] = '*';
			}
		}
		return;
	}
	drawingStars(now / 2, r, c, stars);
	drawingStars(now / 2, r + now/2, c - now/2, stars);
	drawingStars(now / 2, r + now/2, c + now/2, stars);
}

int main(void) {
	int n;
	cin >> n;

	vector<vector<char> > stars;
	stars.resize(n + 1, vector<char>(n * 2 + 1));
	drawingStars(n, 1, n, stars);

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n * 2 + 1; ++j) {
			if (stars[i][j] == '\0') printf(" ");
			else printf("%c", stars[i][j]);
		}
		printf("\n");
	}

	return 0;
}