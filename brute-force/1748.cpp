/* 1748 수이어쓰기1 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int answer = 0;
	int x, tmp_x, cnt = 0;
	cin >> x;
	tmp_x = x;

	/* 자리수 구하기 */
	if (tmp_x == 0) cnt = 1; // 0인 경우, 예외처리
	while (tmp_x>0) { // 그 외
		tmp_x /= 10;
		cnt++;
	}

	/* 더해주기 */
	int j = 1, i;
	if (cnt > 1) { 
		for (i = 1; i < cnt; i++) {
			j *= 10;
			answer += (j - (j / 10))*i;
		}
		answer += (x - j + 1)* (i);
	}
	else {
		answer = x;
	}
	cout << answer << "\n";
	return 0;
}