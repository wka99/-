#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
queue <pair<int, int>> virus;
int map[9][9];
int tmp[9][9];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int maxval = 0;

void virusSpread() {
	int final[9][9];
	queue <pair<int, int>> tv = virus;
	memcpy(final, tmp, sizeof(tmp));
	int x, y;
	while (tv.size()) {
		x = tv.front().first;
		y = tv.front().second;
		tv.pop();
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < N&&y + dy[i] >= 0 && y + dy[i] < M) {
				if (final[x + dx[i]][y + dy[i]]== 0) {
					final[x + dx[i]][y + dy[i]] = 2;
					tv.push({ x + dx[i], y + dy[i] });
				}
			}
		}
	}
	int point = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (final[i][j] == 0)
				point++;
		}
	}
	if (maxval < point)
		maxval = point;
}
void makeWall(int cnt) {
	if (cnt == 3) {
		virusSpread();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				makeWall(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push({ i,j });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				memcpy(tmp, map, sizeof(map));
				tmp[i][j] = 1;
				makeWall(1);
			}
		}
	}
	cout << maxval << endl;
}