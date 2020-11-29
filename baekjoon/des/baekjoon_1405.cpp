#include <iostream>
using namespace std;

/*
�κ��� ���� ���� �ѹ����� ���� �̵����� ���� ��
�̵� ��ΰ� �ܼ��ϴٰ� �Ѵ�.
*/
int map[30][30] = { 0, };
int n;//������ �� �ִ� Ƚ��
double Eprob, Wprob, Sprob, Nprob;
double answer = 0;
void robotMove(int x, int y, double prob, int cnt) {
	if (cnt == n) {
		answer += prob;
		return;
	}
	if (!map[x][y - 1]) { //��
		map[x][y - 1] = 1;
		robotMove(x, y - 1, prob*Eprob, cnt + 1);
		map[x][y - 1] = 0;
	}
	if (!map[x][y + 1]) { //��
		map[x][y + 1] = 1;
		robotMove(x, y + 1, prob*Wprob, cnt + 1);
		map[x][y + 1] = 0;
	}
	if (!map[x+1][y]) { //��
		map[x + 1][y] = 1;
		robotMove(x + 1, y, prob*Sprob, cnt + 1);
		map[x + 1][y] = 0;
	}
	if (!map[x-1][y]) { //��
		map[x - 1][y] = 1;
		robotMove(x - 1, y, prob*Nprob, cnt + 1);
		map[x - 1][y] = 0;
	}
}
int main() {
	cin >> n >> Eprob >> Wprob >> Sprob >> Nprob;
	Eprob /= 100; Wprob /= 100;  Sprob /= 100; Nprob /= 100;
	map[14][14] = 1;
	robotMove(14, 14, 1, 0);
	cout.precision(10);
	cout << answer << endl;
}