#include <iostream>
using namespace std;

int N, M;
int map[51][51];
int visited[51][51];
int dp[51][51];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int play(int x, int y) {
	int mx, my, dist, ret = 0;
	dist = map[x][y];
	if (visited[x][y]) {
		cout << -1 << endl;
		exit(0);
	}
	if (dp[x][y]) return dp[x][y];
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i] * dist;
		my = y + dy[i] * dist;
		if (mx < 0 || mx >= N || my < 0 || my >= M) continue;
		if (!map[mx][my]) continue;
		ret = max(ret, play(mx, my) + 1);
	}
	visited[x][y] = 0;
	return dp[x][y] = ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'H') map[i][j] = 0;
			else map[i][j] = c - '0';
		}
	}
	cout << play(0, 0) + 1 << endl;
}