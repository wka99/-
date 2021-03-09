#include <iostream>
#include <vector>
using namespace std;

int puzzle[9][9];
int col[9][10], row[9][10], square[9][10];
vector<pair<int, int>> blank;

void play(int idx) {
	if (idx == blank.size()) { //¸ðµç Ä­ÀÌ Ã¤¿öÁü
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
}