#include <iostream>
using namespace std;
#define MAX_N 16

int N, answer = 0;
int chess[MAX_N];
//퀸이 서로 공격할 수 없도록 놓는 문제

bool check(int idx) {
	for (int i = 0; i < idx; i++) {
		if (chess[idx] == chess[i]) return false;
		if (abs(idx - i) == abs(chess[idx] - chess[i])) return false;
	}
	return true;
}
void place(int idx) { //idx는 행 위치
	if (idx == N) {
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {
		chess[idx] = i;
		if (check(idx)) {
			place(idx + 1);
		}
	}
}
int main() {
	cin >> N;
	place(0);
	cout << answer << endl;
}