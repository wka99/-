#include <iostream>
using namespace std;
#define MAX 21

int N, M, K;
int x, y;
int map[MAX][MAX];
int dice[6]; //¾Õ, µÚ, À§, ¾Æ·¡, ¿Þ, ¿À

void move(int dir) {
	int d0, d1, d2, d3, d4, d5;
	d0 = dice[0]; d1 = dice[1]; d2 = dice[2];
	d3 = dice[3]; d4 = dice[4]; d5 = dice[5];
	if (dir == 1) { //¿À => ¾Õ, µÚ ¾È¹Ù²ñ
		y++;
		if (y >= M) {
			y--; return;
		}
		dice[2] = d4;
		dice[3] = d5;
		dice[4] = d3;
		dice[5] = d2;
	}
	else if (dir == 2) {//¿Þ
		y--;
		if (y < 0) {
			y++; return;
		}
		dice[2] = d5;
		dice[3] = d4;
		dice[4] = d2;
		dice[5] = d3;
	}
	else if (dir == 3) {//»ó => ¿Þ, ¿À ¾È¹Ù²ñ
		x--;
		if (x < 0) {
			x++; return;
		}
		dice[0] = d3;
		dice[1] = d2;
		dice[2] = d0;
		dice[3] = d1;
	}
	else if (dir == 4) {//ÇÏ
		x++;
		if (x >= N) {
			x--; return;
		}
		dice[0] = d2;
		dice[1] = d3;
		dice[2] = d1;
		dice[3] = d0;
	}
	if (map[x][y]) {
		dice[3] = map[x][y];
		map[x][y] = 0;
	}
	else {
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
	int cmd;
	for (int i = 0; i < K; i++) {
		cin >> cmd;
		move(cmd);
	}
}