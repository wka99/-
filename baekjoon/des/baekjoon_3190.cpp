#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
#define MAX_X 10001

//우, 하, 좌, 상
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[MAX][MAX];
char d_switch[MAX_X];
queue<pair<int, int>> snake;
int N, K, L;

void play(int hx, int hy, int dir, int time) {
	//벽에 닿거나 몸에 닿는 경우, 게임 종료
	if (hx<1 || hx> N || hy<1 || hy> N || map[hx][hy] == 2) {
		cout << time << "\n";
		return;
	}
	if (d_switch[time] == 'L') dir = (dir - 1 + 4) % 4;
	else if (d_switch[time] == 'D') dir = (dir + 1) % 4;
	if (map[hx][hy] == 1) { //사과 먹음
		snake.push({ hx,hy });
		map[hx][hy] = 2;
	}
	else { //사과 없음
		int x = snake.front().first;
		int y = snake.front().second;
		map[x][y] = 0;
		snake.pop(); //꼬리 비우기
		snake.push({ hx,hy });
		map[hx][hy] = 2;
	}
	play(hx + dx[dir], hy + dy[dir], dir, time + 1);
}
int main() {
	int x, y;
	char c;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> c;
		d_switch[x] = c;
	}
	snake.push({ 1,1 });
	play(1, 1, 0, 0);
}