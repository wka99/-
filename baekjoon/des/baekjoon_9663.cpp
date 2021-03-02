#include <iostream>
using namespace std;
#define MAX_N 16

int N, answer = 0;
int chess[MAX_N];
//���� ���� ������ �� ������ ���� ����

bool check(int idx) {
	for (int i = 0; i < idx; i++) {
		if (chess[idx] == chess[i]) return false;
		if (abs(idx - i) == abs(chess[idx] - chess[i])) return false;
	}
	return true;
}
void place(int idx) { //idx�� �� ��ġ
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