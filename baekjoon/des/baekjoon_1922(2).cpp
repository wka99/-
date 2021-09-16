#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define MAX 1001

//MST, Prim 알고리즘

int N, M;
vector<pii> edges[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int visited[MAX];
int ans = 0;

void prim() {
	int curr = 1;//시작 정점
	int cnt = 1;//연결된 정점 개수
	while (1) {
		if (cnt == N) break;
		visited[curr] = true;
		for (auto u : edges[curr]) {
			if (!visited[u.first]) {
				pq.push({ u.second, u.first });
			}
		}
		while (!pq.empty()) {
			pii top = pq.top();
			pq.pop();
			if (!visited[top.second]) {
				visited[top.second] = 1;
				pq.push({ top.first, top.second });
				ans += top.first;
				curr = top.second;
				cnt++;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}
	prim();
	cout << ans << endl;
}