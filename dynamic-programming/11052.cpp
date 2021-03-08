/* 카드 구매하기 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// d[n] : 지불해야하는 금액의 최대값
// d[x] = d[x-1] + p[1], d[x-2] + p[2], d[x-3] + p[3], d[x-n] + p[n] 
int main() {
	int n;
	int p[1001] = {0,};
	int d[1001] = {0,};
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	d[1] = p[1];
	for (int i = 2; i <= n; i++) {
		d[i] = p[i];
		for (int j = 1; j < i; j++) {
			if (d[i] < d[i - j] + p[j]) {
				d[i] = d[i - j] + p[j];
			}
		}
	}
	cout<<d[n]<<"\n";

	
	return 0;
}