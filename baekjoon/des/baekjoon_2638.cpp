#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][100];
int idx[4] = { -1,1,0,0 };//상, 하
int idy[4] = { 0,0,-1,1 };//좌, 우
int visited[100][100] = { 0, };

int remain_cheeze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) return true;
		}
	}
	return false;
}
void BFS(int x, int y) {
	queue<pair<int, int>> q;
	int mx, my;
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + idx[i];
			my = y + idy[i];
			if (mx >= 0 && mx < n&&my >= 0 && my < m) {
				if (!visited[mx][my]&&map[mx][my]==0) {
					visited[mx][my] = 1;
					q.push({ mx,my });
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	queue < pair<int, int>> cheeze;//치즈 위치 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		visited[100][100] = { 0, };
		if (!remain_cheeze()) break;
		BFS(0, 0);
	}
} 