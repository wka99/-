#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//아기상어

int map[20][20] = { 0, };
int check[20][20]; //방문 여부 체크
int ssize = 2;//아기상어의 크기
int cnt = 0;//먹은 생선 수
int time = 0;//물고기를 잡아먹는데 걸린 시간
int N; //map 크기
int dx[4] = { -1,1,0,0 };//상하
int dy[4] = { 0,0,-1,1 };//좌우
int min_dist, minx, miny;

void BFS(int sharki, int sharkj) {
	min_dist = 401;
	minx = 21;
	miny = 21;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			check[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	q.push({sharki, sharkj});
	check[sharki][sharkj] = 0;
	int x, y, mx, my;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			//범위 밖
			if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
			//상어보다 큰 물고기 or 이미 방문한 경우
			if (map[mx][my] > ssize || check[mx][my] != -1) continue;
			check[mx][my] = check[x][y] + 1;
			if (map[mx][my] != 0 && map[mx][my] < ssize) {//먹을 수 있는 물고기
				if (min_dist > check[mx][my]) {
					min_dist = check[mx][my];
					minx = mx;
					miny = my;
				}
				else if (min_dist == check[mx][my]) {
					if (minx > mx) {//위쪽
						minx = mx;
						miny = my;
					}
					else if (minx == mx) {//왼쪽
						if (miny > my) {
							minx = mx;
							miny = my;
						}
					}
				}
			}
			q.push({ mx, my });
		}
	}
}
int main() {
	cin >> N;
	int sharki = 0;//상어의 위치
	int sharkj = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) { //아기상어 위치
				map[i][j] = 0;
				sharki = i;
				sharkj = j;
			}
		}
	}
	while (1) {
		BFS(sharki, sharkj);
		if (minx != 21 && miny != 21) {
			time += check[minx][miny];
			cnt++;
			if (cnt == ssize) {
				ssize++;
				cnt = 0;
			}
			map[minx][miny] = 0;
			sharki = minx;
			sharkj = miny;
		}
		else
			break;
	}
	cout << time << endl;
}