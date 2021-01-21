#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> g[1001];
int visited[1001] = { 0, };
int cnt = 0;

void DFS(int x) {
	visited[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		if (!visited[g[x][i]])
			DFS(g[x][i]);
	}
}
int main() {
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}