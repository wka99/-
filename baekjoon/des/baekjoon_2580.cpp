#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
int visited[81] = { 0, };
vector<pair<int, int>> start = { {0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6} };
int col[9][10];
int row[9][10];
int square[9][10];

void solve(int idx) {
	int x = idx / 9;
	int y = idx % 9;
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}cout << "\n";
		}
		exit(0);
	}
	if (sudoku[x][y] == 0) {
		for (int j = 1; j < 10; j++) {
			if (col[y][j] || row[x][j]) continue;
			if (square[(x / 3) * 3 + y / 3][j]) continue;
			col[y][j] = 1;
			row[x][j] = 1;
			square[(x / 3) * 3 + y / 3][j] = 1;
			sudoku[x][y] = j;
			solve(idx + 1);
			sudoku[x][y] = 0;
			col[y][j] = 0;
			row[x][j] = 0;
			square[(x / 3) * 3 + y / 3][j] = 0;
		}
	}
	else solve(idx + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			col[i][sudoku[j][i]]++;
			row[i][sudoku[i][j]]++;
		}
	}
	//(0,0)(0,3)(0,6)
	//(3,0)(3,3)(3,6)
	//(6,0)(6,3)(6,6)
	int a, b;
	for (int i = 0; i < start.size(); i++) {
		a = start[i].first;
		b = start[i].second;
		for (int j = a; j < a + 3; j++) {
			for (int k = b; k < b + 3; k++) {
				square[i][sudoku[j][k]]++;
			}
		}
	}
	solve(0);
}