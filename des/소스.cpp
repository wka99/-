#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector <int> task[10001];
int time[10001] = { 0, };
int d[10001] = { 0, };
int degree[10001] = { 0, };
queue <int> q;

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			d[i] = time[i];
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < task[x].size(); i++) {
			//���ÿ� ���� ������ �۾� �� �ɸ��� �ð��� ���� ū ���� ã�ƾ� ��
			d[task[x][i]] = max(d[task[x][i]],d[x]+time[task[x][i]]);
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
		for (int j = 1; j <= cnt; j++) {
			cin >> tmp;
			task[tmp].push_back(i);
		}
	}
	topologySort();
	cout << *max_element(d, d + N + 1);
}