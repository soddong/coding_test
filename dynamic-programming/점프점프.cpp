#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int map[1001] = {0,};
int ans[1001] = {0,};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { // input values
		cin >> map[i];
		ans[i] = -1;
	}
	ans[0] = 0;
	for (int i = 0; i < n; i++) { // bottom-up dp 
		if (ans[i] == -1) continue;
		for (int j = 1; j <= map[i]; j++) {
			if (i + j < n) {
				if (ans[i + j] == -1) {
					ans[i + j] = ans[i] + 1;
				}
				else {
					ans[i + j] = min(ans[i + j], ans[i] + 1);
					//cout << ans[i + j] << "\n";
				}
			}
		}
	}
	if (n == 1) cout << "0\n";
	else if (ans[n - 1] == 0) cout << "-1\n";
	else cout << ans[n - 1] << "\n";
	return 0;
}