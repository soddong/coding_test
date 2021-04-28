#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	/* Initialize */
	vector<vector<int>> v(n+2, vector<int>(2, 0)); // 2D vector
	vector<int> sum(n+2, 0); // 1D vector

	/* Input values */
	for(int i = 1; i <= n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	/* Start algorithm */
	for (int i = 1; i <= n; i++) {
		// if days out of range, next index
		if (i + v[i][0] > n+1) {
			continue;
		}
		// override all values after 'i + v[i][0]', if sum is greater
		for (int j = i + v[i][0]; j <= n+1; j++) {
			if (sum[j] < sum[i] + v[i][1])
				sum[j] = sum[i] + v[i][1];
		}
	}

	/* Find answer */
	int answer = 0;
	for (int i = 1; i <= n+1; i++) {
		if (answer < sum[i])
			answer = sum[i];
	}
	cout << answer << endl;
	return 0;
}