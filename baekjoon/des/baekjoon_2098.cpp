#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 17
#define INF 16000001

int N;
int W[MAX_N][MAX_N];
int dp[MAX_N][1 << MAX_N];
int ansBit;

int travel(int cur, int status) {
	if (ansBit == status) {
		if (W[cur][0] == 0) return INF;
		else return W[cur][0];
	}
	if (dp[cur][status] != -1) return dp[cur][status];
	int res = INF;
	for (int i = 0; i < N; i++) {
		if (W[cur][i] == 0) continue;//경로 없음
		if (status & 1 << i) continue;//이미 방문
		res = min(res, travel(i, status | 1 << i) + W[cur][i]);
	}
	return dp[cur][status] = res;
}
int main() {
	cin >> N;
	ansBit = (1 << N) - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << travel(0, 1) << endl;
}