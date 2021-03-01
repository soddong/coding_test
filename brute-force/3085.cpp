/* 3085번 사탕게임 */
#include <iostream>
#include <stdio.h>
#include <vector>
#define N 50
using namespace std;

int check(vector<string> &ca, int n) {
	int max_cnt = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (ca[i][j] == ca[i][j+1])  cnt++;
			else {
				cnt = 1;
			}
			max_cnt = max(cnt, max_cnt);
		}
		cnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (ca[j][i] == ca[j + 1][i])  cnt++;
			else {
				cnt = 1;
			}
			max_cnt = max(cnt, max_cnt);
		}
	}
	return (max_cnt);
}

int main() {
	int n;
	cin >> n;

	// 입력 받기
	vector<string> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int m_candy = 0, ans = 0;
	// 인접한 문자열과 바꾸기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < n - 1) {
				swap(c[i][j], c[i + 1][j]);
				m_candy = check(c, n);
				ans = max(m_candy, ans);
				swap(c[i][j], c[i + 1][j]);
			}
			if (j < n - 1) {
				swap(c[i][j], c[i][j + 1]);
				m_candy = check(c, n);
				ans = max(m_candy, ans);
				swap(c[i][j], c[i][j + 1]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}