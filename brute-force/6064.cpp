/* 6064 ī�� �޷� */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <utility>
using namespace std;
// ����� ��: O(MN)
int main() {
	int T, M, N, x, y;
	cin >> T; // T: test-date count
	for (int t = 0; t < T; t++) {
		bool trigger = 0;
		cin >> M >> N >> x >> y;  // <M, N> : ��������  ->  <x, y> -> <i, j>
		x -= 1;
		y -= 1;
		for (int i = x; i < N * M; i += M) {
			if (i % N == y) {
				cout << i+1 << "\n";
				trigger = 1;
				break;
			}
		}
		if (!trigger) {
			cout << -1 << "\n";
		}
	}

	return 0;
}