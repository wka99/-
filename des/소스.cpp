#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector <int> task[10001];
int time[10001] = { 0, };
int degree[10001] = { 0, };
queue <int> q;
int d[10001] = { 0, };

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			d[i] = time[i];
		}
	}
	int temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 0; i < task[temp].size(); i++) {
			d[task[temp][i]] = max(d[task[temp][i]], d[temp] + time[task[temp][i]]);
			if (--degree[task[temp][i]] == 0) {
				q.push(task[temp][i]);
			}
		}
	}
}
int main() {
	cin >> N;
	int a, b, ftask;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		time[i] = a;
		for (int j = 0; j < b; j++) {
			degree[i]++;
			cin >> ftask;
			task[ftask].push_back(i);
		}
	}
	topologySort();
	cout << *max_element(d, d + N + 1) << endl;
}