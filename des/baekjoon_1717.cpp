#include <iostream>
using namespace std;
int n, m;
int parent[1000001] = { 0, };
//집합의 표현(유니온 파인드)

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[b] = a;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i]=i;
	}
	int op, a, b;
	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if (op == 0)
			Union(a, b);
		else{
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout<< "NO\n";
		}
	}
}