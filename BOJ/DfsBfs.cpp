#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void dfs(int now, vector<vector<int >>& adj, vector<int>& visit) {
	visit[now] = 1;
	cout << now << " ";
	for (auto& e : adj[now]) {
		if (!visit[e]) dfs(e, adj, visit);
	}
}

void bfs(int start, vector<vector<int >>& adj, vector<int>& visit) {
	queue<int> que;
	que.push(start);
	visit[start] = 1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();
		cout << now << " ";

		for (auto& e : adj[now]) {
			if (!visit[e]) {
				visit[e] = 1;
				que.push(e);
			}
		}
	}

}

int main(void) {
	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int> > graph(n + 1);
	vector<int> vis(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int x, y;

		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i)
		sort(graph[i].begin(), graph[i].end());

	dfs(v, graph, vis);
	cout << endl;
	for (int i = 1; i <= n; ++i) vis[i] = 0;
	bfs(v, graph, vis);
	cout << endl;

	return 0;
}