#include <iostream>
#include <queue>
using namespace std;
//적록 색약
int N;
char map[101][101];
int check[101][101] = { 0, };//방문 여부
int idx[4] = { -1,1,0,0 };//위, 아래
int idy[4] = { 0,0,-1,1 };//좌, 우
queue <pair<int, int>> q;

void wrongBfs(int a, int b) {
	q.push(make_pair(a, b));
	int x, y;//현재 위치
	char rgb;//현재 rgb
	int mx, my;//이동 이후의 위치
	char mrgb; //이동한 곳의 rgb
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		check[x][y] = 1;
		q.pop();
		rgb = map[x][y];
		for (int i = 0; i < 4; i++) {
			mx = x + idx[i];
			my = y + idy[i];
			if (mx >= 0 && mx < N&&my >= 0 && my < N&&check[mx][my] == 0) {//범위 내&방문 여부 확인
				mrgb = map[mx][my];
				if (rgb == mrgb) {//일치하는 경우 추가
					q.push(make_pair(mx, my));
				}
			}
		}
	}
}
void bfs(int a, int b) {
	char rgb, nrgb;
	int nx, ny;//이동전
	int mx, my;//이동 후
	q.push({ a,b });
	rgb = map[a][b];
	check[a][b] = 1;
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			mx = nx + idx[i];
			my = ny + idy[i];
			if (mx >= 0 && mx < N&&my>=0 && my < N) {//범위내
				if (check[mx][my] == 0&&map[mx][my]==map[nx][ny]) {//방문한적이 없음
					q.push({ mx,my });
					check[mx][my] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {//적록색맹 아님
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				wrongBfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	cnt = 0;
	for (int i = 0; i < N; i++) {//적록색맹
		for (int j = 0; j < N; j++) {
			check[i][j] = 0;
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				wrongBfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}