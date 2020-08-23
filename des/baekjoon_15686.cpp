#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;

int N, M; //N=도시크기, M=남길 치킨집 수
int city[51][51]; //도시 지도, 0=빈칸, 1=집, 2=치킨
vector <pair<int, int>> chicken; //치킨집 좌표
vector <pair<int, int>> home; //일반집 좌표
int visited[13] = { 0, };
int result = INF; //최단 치킨 거리 저장

void findChicken(int idx, int select) {
	if (select == M) {
		int tmpresult = 0;
		for (int i = 0; i < home.size(); i++) {
			int ed = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					ed = min(ed, abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second));
				}
			}
			tmpresult += ed;
		}
		result = min(result, tmpresult);
		return;
	}
	if (idx == chicken.size())
		return;
	//없애지 않는 경우
	visited[idx] = 1;
	findChicken(idx + 1, select + 1);
	//없애는 경우
	visited[idx] = 0;
	findChicken(idx + 1, select);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
			if (city[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	findChicken(0, 0);
	cout << result << endl;
}