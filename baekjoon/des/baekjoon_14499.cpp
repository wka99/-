#include <iostream>
#include <vector>
using namespace std;

int N, M; //������ ����, ����
int x, y; //�ֻ����� x��ǥ, y��ǥ
int K; //����� ����

int map[21][21] = { 0, }; //����
int command[1001] = { 0, }; //��ɾ�
int dice[6] = { 0, }; //�ֻ��� ��, ��, ��, �Ʒ�, ��, ��

void move(int dir) {
	int tmp, tmp2;
	if (dir == 1) { //�� => ��, �� �ȹٲ�
		y++;
		if (y >= M) {
			y--;
			return;
		}
		tmp = dice[2];
		tmp2 = dice[3];
		dice[2] = dice[4];
		dice[3] = dice[5];
		dice[4] = tmp2;
		dice[5] = tmp;
	}
	else if (dir == 2) { //�� => ��, �� �ȹٲ�
		y--;
		if (y < 0) {
			y++;
			return;
		}
		tmp = dice[2];
		tmp2 = dice[3];
		dice[2] = dice[5];
		dice[3] = dice[4];
		dice[4] = tmp;
		dice[5] = tmp2;
	}
	else if (dir == 3) { //�� => ��, �� �ȹٲ�
		x--;
		if (x < 0) {
			x++;
			return;
		}
		tmp = dice[0];
		tmp2 = dice[1];
		dice[0] = dice[3];
		dice[1] = dice[2];
		dice[2] = tmp;
		dice[3] = tmp2;
	}
	else if (dir == 4) { //�� => ��, �� �ȹٲ�
		x++;
		if (x >= N) {
			x--;
			return;
		}
		tmp = dice[0];
		tmp2 = dice[1];
		dice[0] = dice[2];
		dice[1] = dice[3];
		dice[2] = tmp2;
		dice[3] = tmp;
	}
	if (map[x][y] != 0) {
		dice[3] = map[x][y];
		map[x][y] = 0;
	}
	else if (map[x][y] == 0) {
		map[x][y] = dice[3];
	}
	cout << dice[2] << endl;
}
int main() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> command[i];
	}
	for (int i = 0; i < K; i++) {
		move(command[i]);
	}
}