#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000

vector<vector<int>>v(100, vector<int>(100, 0));
int visited[MAX] = { 0, };

void DFS(int e) {
	visited[e] = 1;
	cout << e << endl;
	for (int i = 0; i < v[e].size(); i++) {
		if (!visited[v[e][i]]) {
			DFS(v[e][i]);
		}
	}
}
void BFS(int e) {
	visited[e] = 1;
	queue<int> q;
	q.push(e);
	int top;
	while (!q.empty()) {
		top = q.front();
		cout << top << endl;
		q.pop();
		for (int i = 0; i < v[top].size(); i++) {
			if (!visited[v[top][i]]) {
				q.push(v[top][i]);
				visited[v[top][i]] = 1;
			}
		}
	}
}
int main() {
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(0);
	v[2].push_back(0);
	v[3].push_back(4);
	v[4].push_back(3);
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
			cout << endl;
		}
	}
	cout << cnt << endl;
}