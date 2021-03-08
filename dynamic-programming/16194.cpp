/* 16194 : buy card 2 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d(n+1);
	vector<int> p(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = p[i];
		for (int j = 1; j < i; j++) {
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n] << "\n";
	return 0;
}

