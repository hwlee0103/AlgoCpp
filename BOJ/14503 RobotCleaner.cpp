#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void cleaning(int r, int c, int d, vector<vector<int> > &board) {

	while (1) {

		//cleaning
		if (board[r][c] == 0) {
			board[r][c] = 2;
			answer++;
		}

		//4 direction
		int i = -1;
		for (; i >= -4; --i) {
			int nextDir = (d + i + 4) % 4;

			if (board[r + dr[nextDir]][c + dc[nextDir]] == 0) {
				d = nextDir;
				r = r + dr[nextDir];
				c = c + dc[nextDir];
				break;
			}
			else {
				continue;
			}
		}

		//all direction
		if (i == -5) {
			if (board[r + dr[(d + 2) % 4]][c + dc[(d + 2) % 4]] != 1) {
				r = r + dr[(d + 2) % 4];
				c = c + dc[(d + 2) % 4];
			}
			else {
				break;
			}
		}
	}

}

int main(void) {
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int> > board(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			board[i][j] = x;
		}
	}

	cleaning(r, c, d, board);
	
	cout << answer << endl;

	return 0;
}