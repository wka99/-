#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	�̼������� ���� �׹������� Ȯ��, Ȯ��Ǵ� ���� x/5
	�ٶ��� �Ҹ� �̼������� �ٶ��� ������ ��ĭ�� �̵�
	T���� �����ִ� �̼������� �� ���
*/

int R, C, T;
int map[51][51];
vector<pair<int, int>> ac;
queue <pair<int, int>> dust;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void spread() {
	int lim = dust.size();
	int x, y, mx, my, originDust;
	
	for (int i = 0; i < lim; i++) {
		x = dust.front().first;
		y = dust.front().second;
		originDust = map[x][y];
		dust.pop();
		for (int j = 0; j < 4; j++) {
			mx = x + dx[j];
			my = y + dy[i];
			if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
			
		}
	}
}
int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				ac.push_back({ i,j });
			else if (map[i][j] > 0) {
				dust.push({ i,j });
			}
		}
	}
}