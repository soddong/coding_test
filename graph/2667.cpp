/* 2667 - 단지 번호 붙이기 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// vector 초기화는 clean

vector<int> v[26];
vector<int> house;
int visited[26][26] = {0,};
int n;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


int dfs(int x, int y, int cnt) {
	//cout << x << " " << y << " " <<cnt<< "\n";
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (visited[nx][ny] == 0 && v[nx][ny] == 1)
				cnt = dfs(nx, ny, ++cnt);
		}
	}
	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) { // input values
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			v[i].push_back(int(tmp[j]) - 48);
		}
	}

	for (int i = 0; i < n; i++) { // 
		for (int j = 0; j < n; j++) {
			//cout << i<<" "<<j<< "\n";
			if (visited[i][j] == 0 && v[i][j] == 1) {
				int tmp = dfs(i, j, 1);
				if (tmp > 0) {
					house.push_back(tmp);
				}
			}
		}
	}
	sort(house.begin(), house.end());
	cout << house.size() << "\n";

	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << "\n";
	}

	cout << "\n";
	return 0;
}