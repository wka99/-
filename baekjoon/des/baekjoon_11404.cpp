#include <iostream>
using namespace std;
#define MAX_N 101
#define INF 10000001
int N, M;
int bus[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int a, b, c;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bus[i][j] = INF;
		}
		bus[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (bus[i][j] == INF) cout << 0 << " ";
			else cout << bus[i][j] << " ";
		}cout << "\n";
	}
}