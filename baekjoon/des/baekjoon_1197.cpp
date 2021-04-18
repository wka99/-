#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_V 10001

//다익스트라로는 MST를 구할 수 없다
//사이클 체크가 이루어지지 않기 때문에 트리를 만들 수 없음

int par[MAX_V]; //사이클 확인을 위한 자료구조
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
int V, E;
int ans = 0;

int Find(int x) {
	if (par[x] == x)return par[x];
	return par[x] = Find(par[x]);
}
bool Union(int x, int y) {
	int px = Find(x);
	int py = Find(y);
	if (px == py) return 0;//사이클이 형성됨
	par[py] = px;
	return 1;
}
void kruskal() {
	int a, b, c;
	while (!pq.empty()) {
		a = pq.top()[1];
		b = pq.top()[2];
		c = pq.top()[0];
		pq.pop();
		if (Union(a, b)) {
			ans += c;
		}
	}
}
int main() {
	cin >> V >> E;
	int a, b, c;
	for (int i = 1; i <= V; i++) par[i] = i;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		pq.push({ c,a,b });
	}
	kruskal();
	cout << ans << endl;
}