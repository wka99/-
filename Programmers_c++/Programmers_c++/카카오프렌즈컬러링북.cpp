#include <vector>
#include <iostream>
using namespace std;

int visited[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int asize, xx, yy;

void DFS(int x, int y, int type, vector<vector<int>> picture) {
	int tx, ty;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < xx&&ty >= 0 && ty < yy) {
			if (picture[tx][ty] == type && !visited[tx][ty]) {
				asize++;
				visited[tx][ty] = 1;
				DFS(tx, ty, type, picture);
			}
		}
	}
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	xx = m; yy = n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && picture[i][j] != 0) {
				asize = 1;
				DFS(i, j, picture[i][j], picture);
				number_of_area++;
				if (max_size_of_one_area < asize) max_size_of_one_area = asize;
			}
		}
	}

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}