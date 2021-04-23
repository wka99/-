#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1001
//MST(Minimum Spanning Tree), Union-Find

int N, M;
vector<vector<int>> edges;
int par[MAX_N];
int ans = 0;

int Find(int x) {
	if (par[x] == x) return par[x];
	return par[x] = Find(par[x]);
}
bool Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	if (px == py) return 0;
	par[py] = px;
	return 1;
}
int main() {
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges.push_back({ c, a, b });
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	for (int i = 0; i < M; i++) {
		a = edges[i][1];
		b = edges[i][2];
		c = edges[i][0];
		if (Union(a, b)) ans += c;
	}
	cout << ans << endl;
}
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001

int N, M;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
int par[MAX];

int Find(int x) {
	if (par[x] == x) return par[x];
	return par[x] = Find(par[x]);
}
bool Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	if (px == py)return 0;
	par[py] = px;
	return 1;
}
int kruskal() {
	int ret = 0;
	int a, b, c;
	while (!pq.empty()) {
		c = pq.top()[0];
		a = pq.top()[1];
		b = pq.top()[2];
		pq.pop();
		if (!Union(a,b)) continue;
		ret += c;
	}
	return ret;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push({ c,a,b });
	}
	cout << kruskal() << endl;
}
*/