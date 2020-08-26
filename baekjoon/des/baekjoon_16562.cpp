#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//친구비

int N, M, k;
int cost[10001] = { 0, };
vector <int> parent;

int Find(int x) {//x의 루트 노드 찾기
	if (x == parent[x])
		return x;
	else {
		return parent[x] = Find(parent[x]);
	}
}
void Union(int x, int y) {//두개 합치기
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (cost[y] > cost[x])
			parent[y] = x;
		else
			parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> k;
	int totalcost = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	parent.push_back(0);
	for (int i = 1; i <= N; i++) {//초기화
		parent.push_back(i);
	}
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <N; i++) { //0에 union시켜 나가면서 루트 노드의 cost를 더해주기
		//union시켜주는 이유는 동일한 값을 또 더하지 않도록
		if (Find(0) != Find(i)) {
			totalcost += cost[Find(i)];
			Union(0, i);
		}
	}
	if (totalcost > k)
		cout << "Oh no\n";
	else
		cout << totalcost << "\n";
}