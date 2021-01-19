#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[9][9];
vector<pair<int, int>> cctv;

void DFS() {
	int x, y, mx, my;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				cctv.push_back({ i,j });
		}
	}
}