#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> empty_p;

bool check(int x, int y) {
	int curr = sudoku[x][y];
	//가로 & 세로 check
	for (int i = 0; i < 9; i++) {
		//세로
		if (i != x && sudoku[i][y] == curr)
			return false;
		//세로
		if (i != y && sudoku[x][i] == curr)
			return false;
	}
	//정사각형 check
	int x_nth = (x / 3) * 3;
	int y_nth = (y / 3) * 3;

	for (int i = x_nth; i < x_nth + 3; i++) {
		for (int j = y_nth; j < y_nth + 3; j++) {
			if (i == x && j == y) continue;
			if (sudoku[i][j] == curr) {
				return false;
			}
		}
	}
	return true;
}
void fill(int idx) {
	if (idx == empty_p.size()) { //스도쿠 판 채워짐
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}cout << "\n";
		}
		exit(0);
	}
	int x, y;
	x = empty_p[idx].first;
	y = empty_p[idx].second;
	for (int i = 1; i < 10; i++) {
		sudoku[x][y] = i;
		if (check(x, y))
			fill(idx + 1);
		sudoku[x][y] = 0; // ** 중요 **
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (!sudoku[i][j])
				empty_p.push_back({ i,j });
		}
	}
	fill(0);
}
/*#include <iostream>
#include <vector>
using namespace std;

int puzzle[9][9];
int col[9][10], row[9][10], square[9][10];
vector<pair<int, int>> blank;

void play(int idx) {
	if (idx == blank.size()) { //모든 칸이 채워짐
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << puzzle[i][j] << " ";
			}cout << endl;
		}
		exit(0);
	}
	int x = blank[idx].first;
	int y = blank[idx].second;
	for (int i = 1; i < 10; i++) {
		if (square[(x / 3) * 3 + y / 3][i]) continue;
		if (col[y][i]) continue;
		if (row[x][i]) continue;
		col[y][i] = 1;
		row[x][i] = 1;
		square[(x / 3) * 3 + y / 3][i] = 1;
		puzzle[x][y] = i;
		play(idx + 1);
		col[y][i] = 0;
		row[x][i] = 0;
		square[(x / 3) * 3 + y / 3][i] = 0;
		puzzle[x][y] = 0;
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> puzzle[i][j];
			if (!puzzle[i][j]) blank.push_back({ i,j });
			row[i][puzzle[i][j]]++;
			col[j][puzzle[i][j]]++;
			square[(i / 3) * 3 + j / 3][puzzle[i][j]]++;
		}
	}
	play(0);
}*/
