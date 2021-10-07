#include <iostream>
using namespace std;
#define MAX 501

int visited[MAX][MAX];
int board[MAX][MAX];
int N, M;
int ans = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void findMax(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (mx < 0 || mx >= N || my < 0 || my >= M)continue;
		if (visited[mx][my])continue;
		visited[mx][my] = 1;
		findMax(mx, my, cnt + 1, sum + board[mx][my]);
		visited[mx][my] = 0;
	}
}
void except(int x, int y) {
	//た
	if (x + 2 < N && y + 1 < M) {
		int sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y + 1];
		ans = max(sum, ans);
	}
	//っ
	if (x + 2 < N && y - 1 >= 0) {
		int sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y - 1];
		ans = max(sum, ans);
	}
	//で
	if (x - 1 >= 0 && y + 2 < M) {
		int sum = board[x][y] + board[x - 1][y + 1] + board[x][y + 1] + board[x][y + 2];
		ans = max(sum, ans);
	}
	//ぬ
	if (x + 1 < N && y + 2 < M) {
		int sum = board[x][y] + board[x + 1][y + 1] + board[x][y + 1] + board[x][y + 2];
		ans = max(sum, ans);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			findMax(i, j, 1, board[i][j]);
			except(i, j);
			visited[i][j] = 0;
		}
	}
	cout << ans << endl;
}