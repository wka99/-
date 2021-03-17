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