#include <iostream>
#include <algorithm>

using namespace std;

/*
	������
	��ư 0���� 9����, +, -
	ä�� N���� �̵��ϱ� ���� ������ �ϴ� ��ư�� �ּ� ����
*/

int N, M;
int schannel = 100;
int buttons[10] = { 0, };
int cnt;

bool psib(int num) { //�Ȱ��峭 ���� ��ư������ ����?
	cnt = 0;
	if (num == 0) {
		if (buttons[num % 10]) return 0;
		else {
			cnt++;
			return 1;
		}
	}
	else {
		while (num > 0) {
			if (buttons[num % 10]) return 0;
			num /= 10;
			cnt++;
		}
	}
	return 1;
}
int main() {
	int diff, tmp;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		buttons[tmp] = 1;
	}
	int target1 = N, target2 = N;
	int d1 = 1000001, d2 = 1000001, minN;
	diff = abs(schannel - N); //+, - ������ �̵�
	if (schannel == N) cout << 0 << endl;
	else {
		while (1) {
			d1 = 1000001;
			d2 = 1000001;
			if (target1 < 1000001 && psib(target1)) {
				d1 = cnt + abs(target1 - N);
			}
			else {
				target1++;
			}
			if (target2 >= 0 && psib(target2)) {
				d2 = cnt + abs(target2 - N);
			}
			else {
				target2--;
			}
			if (d1 != 1000001 || d2 != 1000001) {
				minN = min(d1, min(d2, diff));
				cout << minN << endl;
				break;
			}
			if (target1 >= 1000001 && target2 < 0) {
				cout << diff << endl;
				break;
			}
		}
	}
}