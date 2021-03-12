/* 11724 - 연결 요소의 개수 */
// by c programming
#include <stdio.h>

int g[1001][1001] = { 0, };
int visited[1001] = { 0, };
int n, m;

void dfs(int x) {
	visited[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (g[x][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf_s("%d %d", &u, &v);
		g[u][v] = 1;
		g[v][u] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}