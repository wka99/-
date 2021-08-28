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
/*#include <iostream>
using namespace std;

int N;
int chess[15];
int visited[15];
int ans = 0;

// �� ����� ��� ���� �� �ִ� ����� ���� �ִ�
// 14! => �� ��쿡 ���� Ȯ�� ���� (14+13+..+1) ȸ ����
// �� 87178291200 => 1����� �� 1���̹Ƿ� 800�� => �ð� �ʰ�
// ü���� �ϳ� ���������� Ȯ���ϸ� ��� ����� ���� �ƴ�
// ���� �� �ִ� ��츸 ����� �ǹǷ� �ð� ���� �۾��� ó���� �� �ִ�.

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