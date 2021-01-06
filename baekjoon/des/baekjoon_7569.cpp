#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int boxes[100][100][100] = { 0, };
int check[100][100][100];
queue<vector<int>> riped;//익은 토마토 위치
int dz[6] = { -1,1,0,0,0,0 };//위 아래
int dx[6] = { 0,0,-1,1,0,0 };//앞, 뒤
int dy[6] = { 0,0,0,0,-1,1 };//좌, 우
int leftT = 0;//안익은 토마토 수
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				check[i][j][k] = -1;
				cin >> boxes[i][j][k];
				if (boxes[i][j][k] == 1) {
					riped.push({ i,j,k });
					check[i][j][k] = 0;
				}
				else if (boxes[i][j][k] == 0) {
					leftT++;
				}
			}
		}
	}
	int x, y, z, mx, my, mz;
	int day = 0;
	while (!riped.empty()) {
		z = riped.front()[0];
		x = riped.front()[1];
		y = riped.front()[2];
		riped.pop();
		for (int i = 0; i < 6; i++) {
			mz = z + dz[i];
			mx = x + dx[i];
			my = y + dy[i];
			if (mz < 0 || mz >= H || mx < 0 || mx >= M || my < 0 || my >= N) continue;
			if (boxes[mz][mx][my] == -1) continue;
			if (check[mz][mx][my] == -1) {
				if (boxes[mz][mx][my] == 0) leftT--;
				boxes[mz][mx][my] = 1;
				check[mz][mx][my] = check[z][x][y] + 1;
				day = check[mz][mx][my];
				riped.push({ mz,mx,my });
			}
		}
	}
	if (leftT > 0) cout << -1 << endl;
	else cout << day << endl;
}