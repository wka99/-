#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[20001];
int visited[20001] = { 0, };
int dist[20001] = { 0, };
int maxval = 0;

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	visited[idx] = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < v[top].size(); i++) {
			int curr = v[top][i];
			if (!visited[curr]) {
				dist[curr] = dist[top] + 1;
				if (maxval < dist[curr]) maxval = dist[curr];
				q.push(curr);
				visited[curr] = 1;
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int x, y;
	for (int i = 0; i < edge.size(); i++) {
		x = edge[i][0];
		y = edge[i][1];
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
	for (int i = 2; i <= n; i++) {
		if (maxval == dist[i])
			answer++;
	}
	return answer;
}
int main() {
	solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}
