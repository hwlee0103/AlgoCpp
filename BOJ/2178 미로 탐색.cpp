#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//int board[101][101];

int bfs(int str, int stc, int n, int m, vector<vector<int> > & board) {
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	//r, c
	queue<pair<int, int>> que;
	vector<vector<int> > check(n, vector<int>(m, 0));
	check[str][str] = 1;
	que.push({ str, stc });

	while (!que.empty()) {
		int nowr = que.front().first, nowc = que.front().second;
		int nowCnt = check[nowr][nowc];
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nextr = nowr + dr[i], nextc = nowc + dc[i];
			if (nextr < 0 || nextr >= n || nextc < 0 || nextc >= m) continue;
			if (board[nextr][nextc] && check[nextr][nextc] == 0) {
				check[nextr][nextc] = nowCnt + 1;
				que.push({nextr, nextc});
			}
		}
	}

	return check[n-1][m-1];
}

int main(void) {
	int n, m;
	cin >> n >> m;

	string str;
	vector<vector<int> > board;
	board.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			board[i].push_back(str[j] - '0');
		}
	}

	cout << bfs(0, 0, n, m, board) << endl;

	return 0;
}