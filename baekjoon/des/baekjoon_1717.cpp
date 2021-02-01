#include <iostream>
using namespace std;
#define MAX_N 1000001

int par[MAX_N];

int Find(int x) {
	if (x == par[x]) return par[x];
	return par[x] = Find(par[x]);
}
void Union(int a, int b) {
	int ap = Find(a);
	int bp = Find(b);
	if (ap == bp) return;
	par[bp] = ap;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int c, a, b;
	for (int i = 1; i <= N; i++) { //ÃÊ±âÈ­
		par[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> c >> a >> b;
		if (c == 0) { //union
			Union(a, b);
		}
		else { //find
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}