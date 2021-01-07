#include <iostream>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[51][51] = { 0, };
int visited[51][51] = { 0, };
int T, M, N, K, x, y;

void init() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void DFS(int x, int y) {
	visited[x][y] = 1;
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (mx < 0 || mx >= M || my < 0 || my >= N) continue;
		if (!visited[mx][my]&&map[mx][my]==1) {
			visited[mx][my] = 1;
			DFS(mx, my);
		}
	}
}
int main() {
	cin >> T;
	int worms;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		worms = 0;
		init();
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int a = 0; a < M; a++) {
			for (int b = 0; b < N; b++) {
				if (map[a][b] && !visited[a][b]) {
					DFS(a, b);
					worms++;
				}
			}
		}
		cout << worms << endl;
	}
}