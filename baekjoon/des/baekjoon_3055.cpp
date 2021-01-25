#include <iostream>
#include <queue>
using namespace std;
//bfs

int map[51][51];
int visited[51][51] = { 0, };
int timev[1000000] = { 0, };
vector<pair<int, int>> water;
pair<int, int> bev;
pair<int, int> go;
int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minT = 2500;

void waterSpread() {
	int s = water.size();
	int x, y, mx, my;
	for (int i = 0; i < s; i++) {
		x = water[i].first;
		y = water[i].second;
		for (int j = 0; j < 4; j++) {
			mx = x + dx[j];
			my = y + dy[j];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			if (map[mx][my] == 0 && !(mx == bev.first && my == bev.second)) {
				map[mx][my] = 1;
				water.push_back({ mx,my });
			}
		}
	}
}
void BFS() {
	queue<pair<int, int>> gowhere;
	int x = go.first, y = go.second;
	gowhere.push({ x, y });
	visited[x][y] = 1;
	int mx, my, cnt = 0, flag = 0;
	while (!gowhere.empty()) {
		x = gowhere.front().first;
		y = gowhere.front().second;
		if (x == bev.first && y == bev.second) {
			cout << visited[x][y] - 1 << endl;
			flag = 1;
			return;
		}
		gowhere.pop();
		if (!timev[visited[x][y]]) {
			timev[visited[x][y]] = 1;
			waterSpread();
		}
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			if (!visited[mx][my] && map[mx][my] == 0) { //빈칸으로만 이동 가능
				visited[mx][my] = visited[x][y] + 1;
				gowhere.push({ mx, my });
			}
		}
	}
	if (!flag) {
		cout << "KAKTUS" << endl;
	}
}
int main() {
	char c;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c == 'D') { //비버의 집 => 목적지
				map[i][j] = 0;
				bev = { i,j };
			}
			else if (c == 'S') { //고슴도치 위치
				map[i][j] = 0;
				go = { i,j };
			}
			else if (c == '*') { //물
				map[i][j] = 1;
				water.push_back({ i,j });
			}
			else if (c == 'X') { //돌
				map[i][j] = 2;
			}
			else { //빈칸
				map[i][j] = 0;
			}
		}
	}
	BFS();
}