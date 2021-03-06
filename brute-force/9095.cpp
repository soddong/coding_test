/* 1463 1로만들기 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// D[n] : 연산 횟수
// D[1] = 0, D[2,3] = 1, D[4] = 2, D[5] = 3, D[6] = 2 

int d[1000001];
int dynamic(int x) {
	if (x == 1) return 0;

	if (d[x] > 0) return d[x];
	
	d[x] = dynamic(x - 1) + 1;
	if (x % 3 == 0) {
		int tmp;
		tmp = dynamic(x-1) + 1;
		if (d[x] > tmp) {
			d[x] = tmp;
		}
	}
	if (x % 2 == 0) {
		int tmp;
		tmp = dynamic(x / 2) + 1;
		if (d[x] > tmp) {
			d[x] = tmp;
		}
	}
	return d[x];
}

int main() {
	int x, answer;
	cin >> x;
	answer = dynamic(x);
	cout << answer << "\n";
}