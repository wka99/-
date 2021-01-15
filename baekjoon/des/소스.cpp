#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	ġŲ �Ÿ�: ���� ����� ġŲ�� ������ �Ÿ�
	������ ġŲ �Ÿ�: ��� ���� ġŲ �Ÿ��� ��
	������ ġŲ �Ÿ��� ���� �۰� �ǵ��� �����ų ġŲ�� ����
*/

int N, M, rcnt;
int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int closed[14] = { 0, };
int result = 10001;

int dist() {
	int minD, dist, chiDist = 0;
	for (int i = 0; i < house.size(); i++) {
		minD = 101;
		for (int j = 0; j < chicken.size(); j++) {
			if (!closed[j]) {
				dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				if (minD > dist)minD = dist;
			}
		}
		chiDist += minD;
	}
	return chiDist;
}
void dfs(int idx, int cnt) {
	if (cnt == rcnt) {
		int d = dist();
		if (result > d) result = d;
		return;
	}
	if (idx == chicken.size()) return;
	closed[idx] = 1;
	dfs(idx + 1, cnt + 1);

	closed[idx] = 0;
	dfs(idx + 1, cnt);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
			else if (map[i][j] == 1)
				house.push_back({ i,j });
		}
	}
	rcnt = chicken.size() - M;
	if (M == chicken.size()) {
		cout << dist() << endl;
	}
	else {
		dfs(0, 0);
		cout << result << endl;
	}
}