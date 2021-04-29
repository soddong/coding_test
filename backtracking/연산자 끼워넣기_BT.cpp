#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_val, max_val, n;
vector<int> num;
int oper[4];

// back tracking
void dfs(int idx, int sum) {
	// if index == n, return min-max value
	if (idx == n) {
		if (min_val > sum)
			min_val = sum;
		if (max_val < sum)
			max_val = sum;
	}
	// if index < n, apply all operation case
	else { 
		for (int i = 0; i < 4; i++) {
			if (oper[i] > 0) {
				oper[i] -= 1; // important point.
				if (i == 0)
					dfs(idx + 1, sum + num[idx]);
				else if (i == 1)
					dfs(idx + 1, sum - num[idx]);
				else if (i == 2)
					dfs(idx + 1, sum * num[idx]);
				else if (i == 3) {
					dfs(idx + 1, int(sum / num[idx]));
				}
				oper[i] += 1; // important point.

			}
		}
	}
}

int main() {
	// initialize
	cin >> n;
	num = vector<int>(n, 0);
	min_val = 1000000001;
	max_val = -1000000001;
	
	// input values
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	// Start back tracking algorithm
	dfs(1, num[0]);
	cout << max_val << "\n" << min_val << "\n";
	return 0;
}