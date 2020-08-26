#include <iostream>
using namespace std;

int N, M;
int tetro[501][501];
int visit[501][501] = { 0, };
int dx[4] = { 0,0,-1,1 }; //À§, ¾Æ·¡
int dy[4] = { -1,1,0,0 }; //¿Þ, ¿À
int maxval = 0;

void check(int x, int y, int sum, int cnt) {
	if (visit[x][y]) return;
	if (cnt == 4) {
		if (maxval < sum)
			maxval = sum;
		return;
	}
	int mx, my;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (mx >= 0 && mx < N&&my >= 0 && my < M)
			check(mx, my, sum+ tetro[x][y], cnt+1);
	}
	visit[x][y] = 0;
}
void excep(int x, int y) {
	int sum = 0;
	//1) ¤Ç
	if (y + 2 < M&&x - 1 >= 0) {
		sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x - 1][y + 1];
		if (maxval < sum)
			maxval = sum;
	}
	//2) ¤Ì
	if (y + 2 < M&&x + 1 < N) {
		sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x + 1][y + 1];
		if (maxval < sum)
			maxval = sum;
	}
	//3) ¤Ã
	if (y - 1 >=0&&x + 2 < N) {
		sum = tetro[x][y] + tetro[x + 1][y] + tetro[x + 2][y] + tetro[x + 1][y - 1];
		if (maxval < sum)
			maxval = sum;
	}
	//4) ¤¿
	if (y + 1 < M&&x + 2 < N) {
		sum = tetro[x][y] + tetro[x + 1][y] + tetro[x + 2][y] + tetro[x + 1][y + 1];
		if (maxval < sum)
			maxval = sum;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tetro[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check(i, j, 0, 0);
			excep(i, j);
		}
	}
	cout << maxval << endl;
}