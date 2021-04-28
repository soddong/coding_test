#include <iostream>
#include <vector>
using namespace std;
int n, answer;
vector<vector<int>> v;

void dfs(int cur_day, int total_cost) { // algorithm
	if (cur_day >= n + 1) { // compare answers
		if (answer < total_cost) {
			answer = total_cost;
		}
		return;
	}
	if (cur_day + v[cur_day][0] <= n + 1) // case of choosing this day, move on 'cur_day + v[cur_day][0]'
		dfs(cur_day + v[cur_day][0], total_cost + v[cur_day][1]);
	if (cur_day + 1 <= n + 1) // case of not choosing  this day, move on 'cur_day + 1'
		dfs(cur_day + 1, total_cost);
}

int main() {
	cin >> n;
	v = vector<vector<int>>(n + 2, vector<int>(2, 0)); // 2D vector

	/* Input values */
	for (int i = 1; i <= n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	/* Call dfs function */
	dfs(1, 0);

	cout << answer << endl;
	return 0;
}