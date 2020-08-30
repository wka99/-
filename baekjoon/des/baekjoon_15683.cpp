#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int map[8][8];
int tmp[8][8];
vector <pair<int, int>> cctv;
int result = 100;

void f(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 0)
					cnt++;
			}
		}
		if (result > cnt)
			result = cnt;
		return;
	}
	if (map[cctv[idx].first][cctv[idx].second]==1) {
	}
	else if (map[cctv[idx].first][cctv[idx].second] == 2) {
	}
	else if (map[cctv[idx].first][cctv[idx].second] == 3) {
	}
	else if (map[cctv[idx].first][cctv[idx].second] == 4) {
	}
	else if (map[cctv[idx].first][cctv[idx].second] == 5) {
	}
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
	f(0);
	cout << result << endl;
}