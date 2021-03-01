/* 2309번 일곱난쟁이 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

/* 전 코드 
void print(int* arr, int fake, int fake2) {
	int arr2[7];
	int j = 0;
	for (int i = 0; i < 9; i++){
		if ((arr[i] != arr[fake]) && (arr[i] != arr[fake2])) {
			arr2[j] = arr[i];
			j++;
		}
	}
	for (int i = 0; i < 7; i++) {
		sort(arr2, arr2 + 7);
		cout << arr2[i] << "\n";
	}
}

int main() {
	int a[9];
	int sum = 0;
	int c_sum = 0;

	for (int i = 0; i < 9; i++) {	// 난쟁이의 키 입력받기
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (int i = 0; i < 8; i++) {   // 모든 경우의 수
		for (int j = 1 + i; j < 9; j++) {
			c_sum = a[i] + a[j];
			if (sum - c_sum == 100) {
				print(a, i, j); // 찾은 경우, 출력하는 함수 호출
				return 0;
			}
		}

	}
	return 0;
}
*/


/* 수정 코드 */
int main() {
	int a[9];
	int sum = 0, flag = 0;

	for (int i = 0; i < 9; i++) {	// 난쟁이의 키 입력받기
		scanf("%d", &a[i]);
		sum += a[i]; 
	}
	sort(a, a + 9);
	for (int i = 0; i < 8; i++) {   // 모든 경우의 수
		if (flag == 1) break;
		for (int j = 1 + i; j < 9; j++) {
			if (flag == 1) break;
			if (sum - (a[i] + a[j]) == 100) {
				flag = 1;
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << a[k] << "\n";
				}
			}
		}

	}
	return 0;
}