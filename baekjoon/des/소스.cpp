#include <iostream>
using namespace std;
#define MAX 501

int board[MAX][MAX];
int visit[MAX][MAX];
int N, M;
int maxV = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void excep(int x, int y) {
	//で
	int curr = 0;
	if (y + 2 < M && x - 1 >= 0) {
		curr += board[x][y];
		curr += board[x - 1][y + 1];
		curr += board[x][y + 1];
		curr += board[x][y + 2];
	}
	maxV = max(maxV, curr);
	curr = 0;
	//ぬ
	if (y + 2 < M && x + 1 < N) {
		curr += board[x][y];
		curr += board[x + 1][y + 1];
		curr += board[x][y + 1];
		curr += board[x][y + 2];
	}
	maxV = max(maxV, curr);
	curr = 0;
	//た
	if (x + 2 < N && y + 1 < M) {
		curr += board[x][y];
		curr += board[x + 1][y];
		curr += board[x + 1][y + 1];
		curr += board[x + 2][y];
	}
	maxV = max(maxV, curr);
	curr = 0;
	//っ
	if (y - 1 >= 0 && x + 2 < N) {
		curr += board[x][y];
		curr += board[x + 1][y];
		curr += board[x + 1][y - 1];
		curr += board[x + 2][y];
	}
	maxV = max(maxV, curr);
	curr = 0;
}
void check(int x, int y, int cnt, int sum) {
	if (visit[x][y]) return;
	if (cnt == 4) {
		maxV = max(maxV, sum);
		return;
	}
	int mx, my;
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (mx<0 || mx>N || my<0 || my>M) continue;
		check(mx, my, cnt + 1, sum + board[x][y]);
	}
	visit[x][y] = 0;
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
			check(i, j, 0, 0);
			excep(i, j);
		}
	}
	cout << maxV << endl;
}