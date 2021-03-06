/* 11726 2*n ≈∏¿œ∏µ */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// d[n] : count of ways filled with Rectangle(2*1, 1*2)
// d[n] = d[n-1]*1 + d[n-2]*1
// d[1] = 1
// d[2] = 2

int main() {
	int d[1001];
	int n;
	cin >> n;
	d[1] = 1; d[2] = 2; 
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2])%10007;
	}
	cout << d[n] << "\n";
	return 0;
}