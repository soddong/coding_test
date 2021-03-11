/* 1707 - Bipartite Graph */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int color[20001] = { 0, };
vector<int> g[20001];

bool dfs(int x, int c) {
	color[x] = c;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (color[y] == 0) {
			if (dfs(y, 3 - c) == false) 
				return false;
		}
		else if (color[y] == color[x]) return false;
	}
	return true;
}

int main() {
	int k, v, e;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		for (int j = 0; j < v; j++) {
			g[j].clear();
			color[j] = 0;
		}
		for (int j = 0; j < e; j++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool ok = true;
		for (int l = 1; l <= v; l++) { // search at all vertex
			if (color[l] != 0) {
				if (dfs(l , 1) == false) {
					ok = false;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
	return 0;
}