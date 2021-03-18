#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 501
#define INF 5000001

int N, M;
vector<vector<int>> edge;
/*
underflow가 발생할 수 있어 자료형을 long long으로 선언해주어야 한다
음수 사이클이 존재하게 되면 끝없이 최소값을 갱신하게 되며
cost의 최소값은 -10000, N의 최대값은 500, E의 최대값은 6000으로 
최악의 경우 -10000*500*6000 = -30000000000 이며 이는 int의 범위를 벗어나게 된다.
따라서 long long을 사용해야 하며 int형을 사용할 경우, overflow로 인해
음수 사이클이 존재해 underflow로 인해 -1대신 각 정점으로 가는 최단 거리를
출력하는 경우가 발생할 수 있다.
*/
long long d[MAX_N]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> N >> M;
	//거리 배열 초기화
	for (int i = 2; i <= N; i++) d[i] = INF;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
		if (a == 1) d[b] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = edge[j][0];
			int to = edge[j][1];
			int cost = edge[j][2];
			if (d[from] == INF) continue;
			if (d[to] > d[from] + cost) {
				if (i == N) {
					cout << -1 << "\n";
					return 0;
				}
				else d[to] = d[from] + cost;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (d[i] == INF) cout << -1 << "\n";
		else cout << d[i] << "\n";
	}
}