#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1001
#define INF 1000001
typedef pair<int, int> pii;

int N, M, K;
vector<pii> grph[MAX_N];
vector<int> dist[MAX_N];

void kthDijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int curr = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (dist[curr].size() >= K) continue;
		dist[curr].push_back(val);
		for (int i = 0; i < grph[curr].size(); i++) {
			int next = grph[curr][i].first;
			int nval = grph[curr][i].second;
			pq.push({ val + nval, next });
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) cout << -1 << "\n";
		else cout << dist[i][K - 1] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		grph[a].push_back({ b,c });
	}
	kthDijkstra();
}