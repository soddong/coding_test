// 1654 - 랜선 자르기 
#include stdio.h
#include algorithm
#include vector
#include iostream
using namespace std;

int k, n, cnt;
vectorint len;

bool possible(int mid) {
	cnt = 0;
	for (int i = 0; i  k; i++) {
		cnt += len[i]  mid;
		if (cnt = n) return true;
	}
	return false;
}

int main() {
	int sum = 0, avg;
	scanf_s(%d %d, &k, &n);
	for (int i = 0; i  k; i++) {
		int tmp;
		scanf_s(%d, &tmp);
		len.push_back(tmp);
	}
	sort(len.begin(), len.end());

	int low = 1;
	int high = len[len.size() - 1];
	int result = 0;
	while (low = high) {

		int mid = (low + high)  2;

		if (possible(mid)) {    key 값을 찾았을 때
			if (result  mid)
				result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout  result  n;
	return 0;
}