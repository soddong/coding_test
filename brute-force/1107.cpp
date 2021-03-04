/* 1107 리모콘 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M; // N:이동하려는 채널, M:고장난버튼개수
	cin >> N >> M; 
	int tmp_N = N, cnt = 0;
	for (int j = 0; j < 6; j++) {
		if (tmp_N == 0) break;
		tmp_N /= 10;
		cnt++;
	}
	int worked[10] = { 0, };
	for (int i = 0; i < 10; i++) { // 모든 채널 1로 초기화
		worked[i] = 1;
	}

	for (int i = 0; i < M; i++) { // 고장난 채널은 0값 넣기
		int tmp;
		cin >> tmp;
		worked[tmp] = 0;
	}
	
	int pre1, pre2, answer;
	pre2 = 10000000;
	// 1. just (++/--)
	if (N - 100 >= 0) {
		pre1 = N - 100;
	}
	else if (N - 100 < 0) {
		pre1 = 100 - N;
	}
	int num[6];
	// 2. chennel -> (++/--)
	for (int i = 0; i < 1000000; i++) {
		int tmp_i = i;
		int tmp_cnt = 0;
		if (i == 0) {
			tmp_cnt = 1;
			num[0] = 0;
		}
		else {
			for (int j = 0; j < 6; j++) {
				if (tmp_i == 0) break;
				num[j] = tmp_i % 10;
				tmp_i /= 10;
				tmp_cnt++;
			}
		}
		//cout <<i<<": " << tmp_cnt << " \n";
		int pass = 0;
		for (int j = 0; j < tmp_cnt; j++) {
			if (worked[num[j]] == 1) pass++;
		}
		
		if (pass == tmp_cnt) pre2 = min(pre2, abs(N - i)+ tmp_cnt);
	}
	answer = min(pre1, pre2);
	cout << answer << "\n";
	return 0;
}