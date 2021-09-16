#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 20001
#define INF 200001
typedef pair<int, int> pii;

int V, E, K;
int dist[MAX];
vector<pii>grph[MAX];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	dist[K] = 0;//시작점
	pq.push({ 0,K });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue; //이미 더 작음
		for (int i = 0; i < grph[node].size(); i++) {
			int n_cost = grph[node][i].first;
			int n_node = grph[node][i].second;
			if (dist[n_node] > cost + n_cost) {
				dist[n_node] = cost + n_cost;
				pq.push({ cost + n_cost, n_node });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int u, v, w;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		grph[u].push_back({ w, v });
	}
	for (int i = 1; i <= V; i++) dist[i] = INF;
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}