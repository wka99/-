#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	미세먼지는 인접 네방향으로 확산, 확산되는 양은 x/5
	바람이 불면 미세먼지가 바람의 방향대로 한칸씩 이동
	T초후 남아있는 미세먼지의 양 출력
*/

int R, C, T;
int map[51][51];
vector<pair<int, int>> ac;
queue <pair<int, int>> dust;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int anticlockw[4] = { 3,0,2,1 };//반시계방향
int clockw[4] = { 3,1,2,0 };//시계방향

void spread() {
	int x, y, mx, my, originDust, sDust;
	int tmp[51][51];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[i][j] = map[i][j];
			if (tmp[i][j] != 0) {
				dust.push({ i,j });
			}
		}
	}
	while(!dust.empty()) {
		x = dust.front().first;
		y = dust.front().second;
		originDust = map[x][y];
		sDust = originDust / 5;
		dust.pop();
		if (sDust > 0) {
			for (int j = 0; j < 4; j++) {
				mx = x + dx[j];
				my = y + dy[j];
				if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
				if (map[mx][my] == -1) continue;
				tmp[mx][my] += sDust;
				tmp[x][y] -= sDust;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}
void ac_on() { //공기청정기로 들어간 먼지는 사라짐
	int x, y;
	int tmp[51][51];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	x = ac[0].first;
	y = ac[0].second+1;
	tmp[x][y] = 0;
	for (int i = 0; i < 4; i++) { //반시계
		while (1) {
			int mx = x + dx[anticlockw[i]];
			int my = y + dy[anticlockw[i]];
			if (mx == ac[0].first && my == ac[0].second) break;
			if (mx < 0 || mx >= R || my < 0 || my >= C) break;
			tmp[mx][my] = map[x][y];
			x = mx;
			y = my;
		}
	}
	x = ac[1].first;
	y = ac[1].second+1;
	tmp[x][y] = 0;
	for (int i = 0; i < 4; i++) { //시계
		while (1) {
			int mx = x + dx[clockw[i]];
			int my = y + dy[clockw[i]];
			if (mx == ac[1].first && my == ac[1].second) break;
			if (mx < 0 || mx >= R || my < 0 || my >= C) break;
			tmp[mx][my] = map[x][y];
			x = mx;
			y = my;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				ac.push_back({ i,j });
		}
	}
	for (int i = 0; i < T; i++) {
		spread();
		ac_on();
	}
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0)
				result += map[i][j];
		}
	}
	cout << result << endl;
}