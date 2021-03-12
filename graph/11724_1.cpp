/* 11724 - 연결 요소의 개수 */
// by c++ programming
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[1001];
int visited[1001] = {0,};

void dfs(int x) {
	visited[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (visited[y] == 0)
			dfs(y);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}