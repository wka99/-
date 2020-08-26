#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector <int> task[10001];
queue <int> q;
int degree[10001] = { 0, };
int time[10001] = { 0, };
int d[10001] = { 0, };

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			d[i] = time[i];
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < task[x].size(); i++) {
			//동시에 실행 가능한 작업중 시간이 가장 오래 걸리는 것을 찾아야 한다.
			d[task[x][i]] = max(d[task[x][i]], d[x] + time[task[x][i]]);
			if (--degree[task[x][i]] == 0) {
				q.push(task[x][i]);
			}
		}
	}
}
int main() {
	cin >> N;
	int cnt, tmp;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> cnt;
		degree[i] = cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> tmp;
			task[tmp].push_back(i);
		}
	}
	topologySort();
	cout << *max_element(d, d + N + 1);
}