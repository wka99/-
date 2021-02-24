#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 17
#define INF 10000

int N, P;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N];//status에 따라서만 결과가 달라짐
int onoff = 0, oncnt = 0;

int fix(int status, int cnt) {
	if (cnt >= P) return 0;
	if (dp[status] != -1) return dp[status];
	int res = INF;
	for (int i = 0; i < N; i++) {
		if ((status & 1 << i) == 0) continue;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (status & 1 << j) continue;//이미 켜져있음
			res = min(res, fix(status | 1 << j, cnt + 1) + cost[i][j]);
		}
	}
	return dp[status] = res;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> cost[i][j];
		}
	}
	char c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'Y') {
			onoff = onoff | (1 << i);
			oncnt++;
		}
	}
	cin >> P;
	if (oncnt >= P) {
		cout << 0 << endl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int result = INF;
	result = min(result, fix(onoff, oncnt));
	if (result == INF) cout << -1 << endl;
	else cout << result << endl;
}