#include <vector>
#include <iostream>
using namespace std;

int visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int asize, xx, yy;

void DFS(int x, int y, int type, vector<vector<int>> picture) {
	visited[x][y] = 1;
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = x + dx[i];
		my = y + dy[i];
		if (mx < 0 || mx >= xx || my < 0 || my >= yy) continue;
		if (picture[mx][my] == type && !visited[mx][my]) {
			asize++;
			DFS(mx, my, type, picture);
		}
	}
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	asize = 0;
	xx = m, yy = n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	vector<int> answer(2);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] && !visited[i][j]) {
				number_of_area++;
				asize = 1;
				DFS(i, j, picture[i][j], picture);
				if (max_size_of_one_area < asize) max_size_of_one_area = asize;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
int main() {
	vector<int> a = solution(6, 4, { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
	cout << a[0] << " " << a[1] << endl;
}