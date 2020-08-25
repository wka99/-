#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 50;
const int INF = 2000000000;

int N, M; //���� ũ��, ���� ġŲ�� ����
int map[50][50]; //���� ����
vector <pair<int, int>> home; //�� �ּ�
vector <pair<int, int>> chicken; //ġŲ �� �ּ�
int visit[13] = { 0, }; //ġŲ �� �湮 ����
int result = INF; //ġŲ �Ÿ�

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
	//ġŲ ���� ������ �ʴ� ���
	visit[idx] = 1;
	DFS(idx + 1, dept + 1);
	//���ִ� ���
	visit[idx] = 0;
	DFS(idx + 1, dept);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) { //��
				home.push_back({ i, j });
			}
			if (map[i][j] == 2) { //ġŲ
				chicken.push_back({ i,j });
			}
		}
	}
	DFS(0, 0);
	cout << result << endl;
}