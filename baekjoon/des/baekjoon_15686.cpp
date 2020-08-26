#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;

int N, M; //N=����ũ��, M=���� ġŲ�� ��
int city[51][51]; //���� ����, 0=��ĭ, 1=��, 2=ġŲ
vector <pair<int, int>> chicken; //ġŲ�� ��ǥ
vector <pair<int, int>> home; //�Ϲ��� ��ǥ
int visited[13] = { 0, };
int result = INF; //�ִ� ġŲ �Ÿ� ����

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
	//������ �ʴ� ���
	visited[idx] = 1;
	findChicken(idx + 1, select + 1);
	//���ִ� ���
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