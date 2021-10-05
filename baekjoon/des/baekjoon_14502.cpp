#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9];
queue<pair<int, int>> virus;
vector<pair<int, int>> space;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

void virusSpread() {
	queue<pair<int, int>> q = virus;
	int m[9][9];
	memcpy(m, map, sizeof(map));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int mx, my;
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || my < 0 || mx >= N || my >= M) continue;
			if (m[mx][my])continue;
			m[mx][my] = 2;
			q.push({ mx, my });
		}
	}
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 0)safe++;
		}
	}
	ans = max(ans, safe);
}
void makeWall(int idx, int cnt) {
	if (cnt == 3) {
		virusSpread();
		return;
	}
	if (idx >= space.size()) return;
	int x = space[idx].first;
	int y = space[idx].second;
	map[x][y] = 1;
	makeWall(idx + 1, cnt + 1);
	map[x][y] = 0;
	makeWall(idx + 1, cnt);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push({ i,j });
			else if (map[i][j] == 0)
				space.push_back({ i,j });
		}
	}
	makeWall(0, 0);
	cout << ans << '\n';
}