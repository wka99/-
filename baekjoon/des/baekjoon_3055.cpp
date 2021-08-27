#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 51
//bfs
int map[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int timev[MAX * MAX] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
pair<int, int> bev;
pair<int, int> start;
vector<pair<int, int>> water;
int R, C;

void spread() {
	int size = water.size();
	int x, y, mx, my;
	for (int i = 0; i < size; i++) {
		x = water[i].first; y = water[i].second;
		for (int j = 0; j < 4; j++) {
			mx = x + dx[j];
			my = y + dy[j];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			if (!map[mx][my] && !(bev.first == mx && bev.second == my)) {
				map[mx][my] = 1;
				water.push_back({ mx,my });
			}
		}
	}
}
void bfs() {
	queue<pair<int, int>> q;
	q.push({ start.first, start.second });
	visited[start.first][start.second] = 1;
	int x, y, mx, my;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		//bfs 이므로 가장 처음으로 도착한 것이 최단
		if (x == bev.first && y == bev.second) {
			cout << visited[x][y] - 1 << endl;
			return;
		}
		if (!timev[visited[x][y]]) {
			timev[visited[x][y]] = 1;
			spread();
		}
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			if (!visited[mx][my] && !map[mx][my]) {
				visited[mx][my] = visited[x][y] + 1;
				q.push({ mx, my });
			}
		}
	}
	cout << "KAKTUS\n";
}
int main() {
	char c;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c == '*') {
				water.push_back({ i,j });
				map[i][j] = 1;
			}
			else if (c == 'X') map[i][j] = 2;
			else if (c == 'D') {
				bev.first = i;
				bev.second = j;
			}
			else if (c == 'S') {
				start.first = i;
				start.second = j;
			}
		}
	}
	bfs();
}