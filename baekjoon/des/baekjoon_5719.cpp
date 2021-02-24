#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF 10000001
typedef pair<int, int> pii;

int N, M, S, D;
int g[MAX_N][MAX_N];
vector<int> trace[MAX_N];//노드 x까지 최단 경로로 도착하기 위해서 어떤 노드로부터 왔는지 기록

vector<int> dijkstra() {
	vector<int> d(N, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, S });
	d[S] = 0;
	int node, dist, next, ndist;
	while (!pq.empty()) {
		node = pq.top().second;
		dist = pq.top().first;
		pq.pop();
		if (d[node] < dist) continue;
		for (int i = 0; i < N; i++) {
			if (g[node][i] == -1) continue;
			next = i; ndist = g[node][i];
			if (d[next] > ndist + dist) {
				d[next] = ndist + dist;
				pq.push({ ndist + dist, next });
				trace[next].clear();
				trace[next].push_back(node);
			}
			else if (d[next] == ndist + dist) {
				trace[next].push_back(node);
			}
		}
	}
	return d;
}
void removePath() {
	queue<int> q;
	q.push(D);
	while (!q.empty()) {
		int to = q.front();
		q.pop();
		for (int i = 0; i < trace[to].size(); i++) {
			int from = trace[to][i];
			if (g[from][to] == -1) continue;
			g[from][to] = -1;
			q.push(from);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int u, v, p;
	while (1) {
		memset(g, -1, sizeof(g));
		for (int i = 0; i < MAX_N; i++)trace[i].clear();
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> p;
			g[u][v] = p;
		}
		dijkstra();
		removePath();
		vector<int> dist = dijkstra();
		if (dist[D] == INF) cout << -1 << "\n";
		else cout << dist[D] << "\n";
	}
}