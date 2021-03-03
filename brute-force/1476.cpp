/*1476 날짜계산*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// 지구 : E, 태양 : S, 달 : M
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);
	//cin >> E >> S >> M;
	// E <= 15, S <= 28, M <= 19

	int i = 0;
	int answer;
	while (1) {
		int y = i * 15 + (E-1);

		if (y % 28 == (S-1) && y % 19 == (M-1)) {
			answer = y;
			break;
		}
		i++;
	}
	cout << answer+1 << "\n";
	return 0;
}