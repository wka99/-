#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF 10000
//플로이드 워셜 알고리즘을 사용하여 모든 정점 사이의 경로를 파악

int N, M;
int d[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b] = 1;//경로 존재
	}
	//플로이드 와샬
	for (int k = 1; k <= N; k++) { //중간
		for (int i = 1; i <= N; i++) { //출발
			for (int j = 1; j <= N; j++) { //도착
				if (d[i][k] && d[k][j])
					d[i][j] = 1;
			}
		}
	}
	int j, ans = 0;
	for (int i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (!d[j][i] && !d[i][j] && i != j) break;
		}
		if (j == N + 1) ans++;
	}
	cout << ans << endl;
}