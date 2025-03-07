#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_V 20001
#define INF 3000001
/*
	플로이드 워셜의 경우
	최대 20000^3 = 8000000000 연산 필요, 제한 시간내 해결 불가
	 + 메모리 초과
	벨만 포드의 경우
	최대 20000*300000 = 6000000000 연산 필요, 제한 시간내 해결 불가
	따라서 dijkstra 사용
*/
int V, E, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>>grph[MAX_V];
int D[MAX_V];

void bfs() {
	D[K] = 0;
	pq.push({ 0, K });
	int node, dist;
	while (!pq.empty()) {
		node = pq.top().second;
		dist = pq.top().first;
		pq.pop();
		if (D[node] < dist) continue;
		for (int i = 0; i < grph[node].size(); i++) {
			int next = grph[node][i].first;
			int ndist = grph[node][i].second;
			if (D[next] > ndist + dist) {
				D[next] = ndist + dist;
				pq.push({ dist + ndist, next });
			}
		}
	}
}
int main() {
	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		grph[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) D[i] = INF;
	bfs();
	for (int i = 1; i <= V; i++) {
		if (D[i] == INF) cout << "INF\n";
		else cout << D[i] << "\n";
	}
}