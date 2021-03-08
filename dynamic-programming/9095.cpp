/* 9095 - 1,2,3 더하기 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// d[n] : 1, 2, 3으로 나타내는 방법의 수
// d[n] = d[n-1] + d[n-2] + d[n-3]
int main() {
	int d[12];
	int T;
	cin >> T;
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 0; i < T; i++) { // test case's count
		int n;
		cin >> n;
		for (int j = 4; j <= n; j++) { // find result
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		}
		cout << d[n] << "\n";
	}

	return 0;
}
