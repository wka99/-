#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
int map[51][51];
vector<int> ac; //공기청정기 위치
queue <pair<int, int>> dust; //먼지 위치
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int clock[4] = { 3,1,2,0 }; //시계
int anticlock[4] = { 3,0,2,1 }; //반시계

void spread() { //미세먼지 확산
	int tmp[51][51];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0)
				dust.push({ i,j });
			tmp[i][j] = map[i][j];
		}
	}
	int x, y, mx, my, sdust;
	while (!dust.empty()) {
		x = dust.front().first;
		y = dust.front().second;
		sdust = map[x][y] / 5;
		dust.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			if (map[mx][my] == -1) continue;
			tmp[mx][my] += sdust;
			tmp[x][y] -= sdust;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}
void ac_on() { //공기청정기 작동
	int tmp[51][51];
	int x, y, mx, my;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	//반시계
	x = ac[0];
	y = 1;
	tmp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		while (1) {
			mx = x + dx[anticlock[i]];
			my = y + dy[anticlock[i]];
			if (mx < 0 || mx >= R || my < 0 || my >= C) break;
			if (mx == ac[0] && my == 0) break;
			tmp[mx][my] = map[x][y];
			x = mx;
			y = my;
		}
	}
	//시계
	x = ac[1];
	y = 1;
	tmp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		while (1) {
			mx = x + dx[clock[i]];
			my = y + dy[clock[i]];
			if (mx < 0 || mx >= R || my < 0 || my >= C) break;
			if (mx == ac[1] && my == 0) break;
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
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				ac.push_back(i);
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