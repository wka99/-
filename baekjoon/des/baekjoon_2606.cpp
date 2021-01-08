#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//바이러스에 걸리는 컴퓨터의 개수 출력

vector<int> coms[101];
int visited[101] = { 0, };
queue<int> q;
int main() {
	int num, edge, a, b;
	cin >> num >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		coms[a].push_back(b);
		coms[b].push_back(a);
	}
	int f, cnt = 0;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		f = q.front();
		if (f != 1) cnt++;
		q.pop();
		for (int i = 0; i < coms[f].size(); i++) {
			if (!visited[coms[f][i]]) {
				q.push(coms[f][i]);
				visited[coms[f][i]] = 1;
			}
		}
	}
	cout << cnt << endl;
}