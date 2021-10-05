#include <iostream>
#include <vector>
using namespace std;
#define MAX 21

int N, M, x, y, K;
int map[MAX][MAX];
vector<int> dice1(4, 0), dice2(3, 0);
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int dir, mx, my;
	for (int i = 0; i < K; i++) {
		cin >> dir;
		mx = x + dx[dir - 1];
		my = y + dy[dir - 1];
		if (mx < 0 || my < 0 || mx >= N || my >= M)continue;
		if (dir == 1) {
			int tmp = dice1[3];
			dice1[3] = dice2[0];
			dice2.erase(dice2.begin());
			dice2.push_back(tmp);
			dice1[1] = dice2[1];
		}
		else if (dir == 2) {
			int tmp = dice1[3];
			dice1[3] = dice2[2];
			dice2.pop_back();
			dice2.insert(dice2.begin(), tmp);
			dice1[1] = dice2[1];
		}
		else if (dir == 4) {
			int top = dice1[0];
			dice1.erase(dice1.begin());
			dice1.push_back(top);
			dice2[1] = dice1[1];
		}
		else {
			int back = dice1.back();
			dice1.pop_back();
			dice1.insert(dice1.begin(), back);
			dice2[1] = dice1[1];
		}
		if (map[mx][my] == 0) { //¹Ù´Ú¸éÀÌ 0ÀÎ °æ¿ì
			map[mx][my] = dice1[1];
		}
		else { //¹Ù´Ú¸éÀÌ 0ÀÌ ¾Æ´Ô
			dice1[1] = map[mx][my];
			dice2[1] = map[mx][my];
			map[mx][my] = 0;
		}
		cout << dice1[3] << '\n';
		x = mx; y = my;
	}
}