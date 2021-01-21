#include <iostream>
#include <vector>
using namespace std;

//파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법
//빈칸 0, 벽 1

int N;
int house[17][17]; //집 지도
vector<pair<int, int>> pipe;
//0:가로, 1:대각선, 2:세로
int dx[3] = { 0,1,1 };
int dy[3] = { 1,1,0 };
vector<int> movement[3] = { {0, 1}, {0, 1, 2}, {1, 2} };
int cnt = 0;

void dfs(int type) {
	pair<int, int> p1 = pipe[0];
	pair<int, int> p2 = pipe[1];
	if ((p1.first == N - 1 && p1.second == N - 1) || (p2.first == N - 1 && p2.second == N - 1)) {
		cnt++;
		return;
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < movement[type].size(); i++) {
		x1 = p2.first;
		y1 = p2.second;
		x2 = p2.first + dx[movement[type][i]];
		y2 = p2.second + dy[movement[type][i]];
		if (x1 >= N || y1 >= N || x2 >= N || y2 >= N) continue;
		if (house[x1][y1] == 1 || house[x2][y2] == 1) continue;
		if (movement[type][i] == 1) {
			if (house[p2.first + 1][p2.second] == 1) continue;
			if (house[p2.first][p2.second + 1] == 1) continue;
		}
		pipe[0] = { x1, y1 };
		pipe[1] = { x2, y2 };
		dfs(movement[type][i]);
		pipe[0] = p1;
		pipe[1] = p2;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}
	pipe.push_back({ 0,0 });
	pipe.push_back({ 0,1 });
	dfs(0);
	cout << cnt << endl;
}