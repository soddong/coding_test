/* 1260 DFS and BFS */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
bool check[1001];
vector<int> a[1001];

void dfs(int node) {
	check[node] = true;
	cout << node << " ";
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		cout << node << " ";
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end()); //a[i] inner sorting
	}
	dfs(start);
	cout << "\n";
	bfs(start);
	cout<<"\n";
	return 0;
}