#include <iostream>
using namespace std;

int alpha[26] = { 0, };
char map[20][20];
int idx[4] = { -1,1,0,0 };
int idy[4] = { 0,0,-1,1 };
int answer = 0;
int R, C;

void check(int x, int y, int ans) {
	int mx, my, cnt = 0;
	for (int i = 0; i < 4; i++) {
		mx = x + idx[i];
		my = y + idy[i];
		if (mx >= 0 && mx < R&&my >= 0 && my < C) {
			if (!alpha[map[mx][my] - 'A']) {
				alpha[map[mx][my] - 'A'] = 1;
				check(mx, my, ans + 1);
				alpha[map[mx][my] - 'A'] = 0;
			}
			else cnt++;
		}
		else cnt++;
	}
	if (cnt == 4) {
		if (answer < ans) answer = ans;
	}
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	alpha[map[0][0] - 'A'] = 1;
	check(0, 0, 1);
	cout << answer << endl;
}