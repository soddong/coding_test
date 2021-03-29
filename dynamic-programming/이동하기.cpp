// baekjoon 11048 - move
#include <iostream>
#include <algorithm>
using namespace std;

int candy[1001][1001];
int a[1001][1001] = {0,};

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> candy[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = max(max(a[i - 1][j - 1], a[i - 1][j]), a[i][j - 1]) + candy[i][j];
		}
	}

	cout << a[n][m] << "\n";
	return 0;
}