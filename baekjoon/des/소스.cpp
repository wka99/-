#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 51
#define MAX_T 2501

int R, C;
int map[MAX][MAX];
int visited[MAX][MAX];
int timev[MAX_T];
int sx, sy;//고슴도치 위치
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> water;
int ans = MAX_T;

void spread() {
	int s = water.size();
	int x, y, mx, my;
	for (int i = 0; i < s; i++) {
		x = water[i].first;
		y = water[i].second;
		for (int j = 0; j < 4; j++) {
			mx = x + dx[j];
			my = y + dy[j];
			if (mx < 0 || my < 0 || mx >= R || my >= C) continue;
			if (map[mx][my]) continue;
			map[mx][my] = 1;
			water.push_back({ mx,my });
		}
	}
}
void travel() {
	int x, y, mx, my;
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (map[x][y] == 3) {
			ans = visited[x][y] - 1;
			return;
		}
		if (!timev[visited[x][y]]) {
			timev[visited[x][y]] = 1;
			spread();
		}
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || my < 0 || mx >= R || my >= C)continue;
			if (map[mx][my] == 1 || map[mx][my] == 2) continue;
			if (visited[mx][my]) continue;
			q.push({ mx, my });
			visited[mx][my] = visited[x][y] + 1;
		}
	}
}
int main() {
	char tmp;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> tmp;
			if (tmp == 'D') {//비버집
				map[i][j] = 3;
			}
			else if (tmp == 'S') {
				sx = i; sy = j;
			}
			else if (tmp == 'X') {//돌멩이
				map[i][j] = 2;
			}
			else if (tmp == '*') {//물
				map[i][j] = 1;
				water.push_back({ i,j });
			}
		}
	}
	travel();
	if (ans == MAX_T) cout << "KAKTUS\n";
	else cout << ans << "\n";
}