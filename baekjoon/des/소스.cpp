#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 20001
#define INF 200001

int V, E;
vector<pair<int,int>> edge[MAX];
int dist[MAX];

void dijkstra() {
	memset(dist, INF, sizeof(dist));
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, 1 });
	int cost, node;
	while (!pq.empty()) {
		cost = pq.top().first;
		node = pq.top().second;
		pq.pop();

	}
}
int main() {
	cin >> V >> E;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ v,w });
	}
	dijkstra();
}