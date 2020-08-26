#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 50;
const int INF = 2000000000;

int N, M; //도시 크기, 남길 치킨집 개수
int map[50][50]; //도시 지도
vector <pair<int, int>> home; //집 주소
vector <pair<int, int>> chicken; //치킨 집 주소
int visit[13] = { 0, }; //치킨 집 방문 여부
int result = INF; //치킨 거리

void DFS(int idx, int dept) {
	if (dept == M) {
		int tmpresult = 0;
		for (int i = 0; i < home.size(); i++) {
			int tmp = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (visit[j]) {
					tmp = min(tmp, abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second));
				}
			}
			tmpresult += tmp;
		}
		result = min(result, tmpresult);
		return;
	}
	if (idx >= chicken.size())
		return;
	//치킨 집을 없애지 않는 경우
	visit[idx] = 1;
	DFS(idx + 1, dept + 1);
	//없애는 경우
	visit[idx] = 0;
	DFS(idx + 1, dept);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) { //집
				home.push_back({ i, j });
			}
			if (map[i][j] == 2) { //치킨
				chicken.push_back({ i,j });
			}
		}
	}
	DFS(0, 0);
	cout << result << endl;
}