#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//줄 세우기 (위상 정렬)

int N, M;
vector <int> student[32001];
int degree[32001] = { 0, };
queue <int> tmp;

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			tmp.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (tmp.empty())
			return;
		int x = tmp.front();
		cout << x << " ";
		tmp.pop();
		for (int j = 0; j < student[x].size(); j++) {
			if (--degree[student[x][j]] == 0) {
				tmp.push(student[x][j]);
			}
		}
	}cout << endl;
}
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		degree[b]++;
		student[a].push_back(b);
	}
	topologySort();
}