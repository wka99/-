#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//�Ʊ���

int map[20][20] = { 0, };
int check[20][20]; //�湮 ���� üũ
int ssize = 2;//�Ʊ����� ũ��
int cnt = 0;//���� ���� ��
int time = 0;//����⸦ ��ƸԴµ� �ɸ� �ð�
int N; //map ũ��
int dx[4] = { -1,1,0,0 };//����
int dy[4] = { 0,0,-1,1 };//�¿�
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
			//���� ��
			if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
			//���� ū ����� or �̹� �湮�� ���
			if (map[mx][my] > ssize || check[mx][my] != -1) continue;
			check[mx][my] = check[x][y] + 1;
			if (map[mx][my] != 0 && map[mx][my] < ssize) {//���� �� �ִ� �����
				if (min_dist > check[mx][my]) {
					min_dist = check[mx][my];
					minx = mx;
					miny = my;
				}
				else if (min_dist == check[mx][my]) {
					if (minx > mx) {//����
						minx = mx;
						miny = my;
					}
					else if (minx == mx) {//����
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
	int sharki = 0;//����� ��ġ
	int sharkj = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) { //�Ʊ��� ��ġ
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