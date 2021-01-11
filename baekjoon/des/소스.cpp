#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<int> coms[101];
	int visited[101] = { 0, };
	int comN, edges, f, cnt = 0;
	int a, b;
	cin >> comN >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> a >> b;
		coms[a].push_back(b);
		coms[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		f = q.front();
		q.pop();
		for (int i = 0; i < coms[f].size(); i++) {
			if (!visited[coms[f][i]]) {
				visited[coms[f][i]] = 1;
				q.push(coms[f][i]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}