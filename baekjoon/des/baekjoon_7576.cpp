#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int box[1000][1000] = { 0, }; //안익은거 0, 익은거 1
int check[1000][1000];
queue<pair<int, int>> riped;//익은 토마토 위치
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = -1;
			cin >> box[i][j];
			if (box[i][j] == 1) {
				riped.push({ i,j });
				check[i][j] = 0;
			}
		}
	}
	int x, y, mx, my;
	int day = 0;
	while (!riped.empty()) {
		x = riped.front().first;
		y = riped.front().second;
		riped.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || mx >= M || my < 0 || my >= N) continue;
			if (box[mx][my] == -1) continue; //빈공간 이동 불가
			if (check[mx][my] == -1) {
				box[mx][my] = 1;
				riped.push({ mx,my });
				check[mx][my] = check[x][y] + 1;
				day = check[mx][my];
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 0) {
				cout << -1 << endl;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	if(!flag)
		cout << day << endl;
}