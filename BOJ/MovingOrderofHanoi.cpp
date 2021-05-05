#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > que;

int hanoi(int now, int start, int mid, int end) {
	int cnt = 0;

	if (now == 1) {
		que.push({ start, end });
		return ++cnt;
	}
	cnt += hanoi(now - 1, start, end, mid);
	que.push({ start, end });
	cnt++;
	cnt += hanoi(now - 1, mid, start, end);
	return cnt;
}

int main(void) {
	int n;
	cin >> n;
	cout << hanoi(n, 1, 2, 3) << endl;
	while (!que.empty()) {
		//cout << que.front().first << " " << que.front().second << endl;
		printf("%d %d\n", que.front().first, que.front().second);
		que.pop();
	}

	return 0;
}