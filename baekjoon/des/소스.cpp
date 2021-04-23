#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 501
#define INF 5000001

int dist[MAX_N];
vector<pair<int, int>> grph[MAX_N];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)dist[i] = INF;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		grph[a].push_back({ b,c });
	}
}