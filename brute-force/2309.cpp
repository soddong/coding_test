/* 2309�� �ϰ������� */
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

/* �� �ڵ� 
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

	for (int i = 0; i < 9; i++) {	// �������� Ű �Է¹ޱ�
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (int i = 0; i < 8; i++) {   // ��� ����� ��
		for (int j = 1 + i; j < 9; j++) {
			c_sum = a[i] + a[j];
			if (sum - c_sum == 100) {
				print(a, i, j); // ã�� ���, ����ϴ� �Լ� ȣ��
				return 0;
			}
		}

	}
	return 0;
}
*/


/* ���� �ڵ� */
int main() {
	int a[9];
	int sum = 0, flag = 0;

	for (int i = 0; i < 9; i++) {	// �������� Ű �Է¹ޱ�
		scanf("%d", &a[i]);
		sum += a[i]; 
	}
	sort(a, a + 9);
	for (int i = 0; i < 8; i++) {   // ��� ����� ��
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