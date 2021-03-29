#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 21

int N;
vector<vector<int>> map(MAX_N, vector<int>(MAX_N, 0));
int ans = 0;

void UP(vector<vector<int>> map, vector<vector<int>>& ret) {
	for (int x = 0; x < N; x++) {
		vector<int> newlines;
		int flag = 0;
		for (int y = 0; y < N; y++) {
			if (map[y][x] == 0) continue;
			if (!flag) {
				newlines.push_back(map[y][x]);
				flag = 1;
			}
			else {
				int f = newlines[newlines.size() - 1];
				newlines.pop_back();
				if (f == map[y][x]) {
					f += map[y][x];
					newlines.push_back(f);
					flag = 0;
				}
				else {
					newlines.push_back(f);
					newlines.push_back(map[y][x]);
				}
			}
		}
		int idx = 0;
		for (int z = 0; z < newlines.size(); z++) {
			ret[idx++][x] = newlines[z];
		}
	}
}
void DOWN(vector<vector<int>> map, vector<vector<int>>& ret) {
	for (int x = 0; x < N; x++) {
		vector<int> newlines;
		int flag = 0;
		for (int y = N - 1; y >= 0; y--) {
			if (map[y][x] == 0) continue;
			if (!flag) {
				newlines.push_back(map[y][x]);
				flag = 1;
			}
			else {
				int f = newlines[newlines.size() - 1];
				newlines.pop_back();
				if (f == map[y][x]) {
					f += map[y][x];
					newlines.push_back(f);
					flag = 0;
				}
				else {
					newlines.push_back(f);
					newlines.push_back(map[y][x]);
				}
			}
		}
		int idx = N - 1;
		for (int z = 0; z < newlines.size(); z++) {
			ret[idx--][x] = newlines[z];
		}
	}
}
void LEFT(vector<vector<int>> map, vector<vector<int>>& ret) {
	for (int x = 0; x < N; x++) {
		vector<int> newlines;
		int flag = 0;
		for (int y = 0; y < N; y++) {
			if (map[x][y] == 0) continue;
			if (!flag) {
				newlines.push_back(map[x][y]);
				flag = 1;
			}
			else {
				int f = newlines[newlines.size() - 1];
				newlines.pop_back();
				if (f == map[x][y]) {
					f += map[x][y];
					newlines.push_back(f);
					flag = 0;
				}
				else {
					newlines.push_back(f);
					newlines.push_back(map[x][y]);
				}
			}
		}
		int idx = 0;
		for (int z = 0; z < newlines.size(); z++) {
			ret[x][idx++] = newlines[z];
		}
	}
}
void RIGHT(vector<vector<int>> map, vector<vector<int>>& ret) {
	for (int x = 0; x < N; x++) {
		vector<int> newlines;
		int flag = 0;
		for (int y = N - 1; y >= 0; y--) {
			if (map[x][y] == 0) continue;
			if (!flag) {
				newlines.push_back(map[x][y]);
				flag = 1;
			}
			else {
				int f = newlines[newlines.size() - 1];
				newlines.pop_back();
				if (f == map[x][y]) {
					f += map[x][y];
					newlines.push_back(f);
					flag = 0;
				}
				else {
					newlines.push_back(f);
					newlines.push_back(map[x][y]);
				}
			}
		}
		int idx = N - 1;
		for (int z = 0; z < newlines.size(); z++) {
			ret[x][idx--] = newlines[z];
		}
	}
}
void play(int move,  vector<vector<int>> map) {
	if (move == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, map[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> ret(N, vector<int>(N, 0));
		if (i == 0) UP(map, ret);
		else if (i == 1) DOWN(map, ret);
		else if (i == 2) LEFT(map, ret);
		else if (i == 3) RIGHT(map, ret);
		play(move + 1, ret);
	}
}
int main() {
	int num;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}
	play(0, map);
	cout << ans << endl;
}