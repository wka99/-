#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 101
#define MAX_X 10001

int map[MAX_N][MAX_N];
char movement[MAX_X];
queue<pair<int, int>> snake;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, K, L;

void play(int hx, int hy, int t, int dir) {
	if (hx < 1 || hy < 1 || hx > N || hy > N || map[hx][hy] == 2) {
		cout << t << endl;
		return;
	}
	if (movement[t] == 'L')
		dir = (dir - 1 + 4) % 4;
	else if (movement[t] == 'D')
		dir = (dir + 1) % 4;
	int mx, my;
	if (map[hx][hy] == 0) { //이동 위치에 사과가 없는 경우
		map[hx][hy] = 2;
		snake.push({ hx, hy });
		int tx = snake.front().first;
		int ty = snake.front().second;
		snake.pop();//꼬리를 비워준다
		map[tx][ty] = 0;
	}
	else {
		map[hx][hy] = 2;
		snake.push({ hx, hy });
	}
	mx = hx + dx[dir];
	my = hy + dy[dir];
	play(mx, my, t + 1, dir);
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
		movement[x] = c;
	}
	snake.push({ 1, 1 });
	play(1, 1, 0, 1);
}