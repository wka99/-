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
/*#include <iostream>
using namespace std;

int N;
int chess[15];
int visited[15];
int ans = 0;

// 이 방법의 경우 만들 수 있는 경우의 수가 최대
// 14! => 각 경우에 대해 확인 과정 (14+13+..+1) 회 수행
// 총 87178291200 => 1억번당 약 1초이므로 800초 => 시간 초과
// 체스를 하나 놓을때마다 확인하면 모든 경우의 수가 아닌
// 놓을 수 있는 경우만 만들게 되므로 시간 내에 작업을 처리할 수 있다.

bool check() {
	for (int i = 1; i <= N-1; i++) {
		for (int j = i+1; j <= N; j++) {
			if (abs(chess[i] - chess[j]) == abs(i - j))
				return false;
		}
	}
	return true;
}
void place(int idx) {
	if (idx == N + 1) {
		if (check()) ans++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			chess[idx] = i;
			place(idx + 1);
			visited[i] = 0;
			chess[idx] = 0;
		}
	}
}
int main() {
	cin >> N;
	place(1);
	cout << ans << endl;
}*/