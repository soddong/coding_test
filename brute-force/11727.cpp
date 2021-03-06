#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// d[n] : counts of ways filled with Rectangle(2*1, 1*2, 2*2)
// d[n] = d[n-1] + 2*d[n-2]

/* 1. bottom-up using vector */
//int main() {
//	vector<int> d;
//	int n;
//	cin >> n;
//	d.push_back(1);
//	d.push_back(3);
//	for (int i = 2; i < n; i++) {
//		int tmp = d.at(i - 1) + 2 * d.at(i - 2);
//		d.push_back(tmp);
//	}
//	cout << d.at(n-1) << "\n";
//	return 0;
//}

/* 2. bottom-up using array */
//int main() {
//	int d[1001];
//	int n;
//	cin >> n;
//	d[1] = 1; d[2] = 3;
//	for (int i = 3; i <= n; i++) {
//		d[i] = (d[i - 1] + 2 * d[i - 2])%10007;
//	}
//	cout << d[n] << "\n";
//	return 0;
//}

/* 3. top-down using array */
int d[1001];
int dynamic(int x) {
	if (x == 1) return 1;
	else if (x == 2) return 3;
	else {
		if (d[x] > 0) return d[x];
		else {
			d[x] = (dynamic(x - 1) + 2 * dynamic(x - 2))%10007;
			return d[x];
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	cout << dynamic(n) << "\n";
	return 0;
}