#include <iostream>
#include <cstring>
using namespace std;
#define MAX 31

//동쪽의 사이트 M개중 N개를 고르는 방법을 찾는것
//mCn과 일치

int dp[MAX][MAX];
int solve(int m, int n) {
	if (dp[m][n] != 0) return dp[m][n];
	if (n == m || n == 0) return dp[m][n] = 1;
	if (n == 1) return dp[m][n] = m;
	dp[m][n] = solve(m - 1, n - 1) + solve(m - 1, n);
	return dp[m][n];
}
int main() {
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(dp, 0, sizeof(dp));
		cin >> N >> M;
		cout << solve(M, N) << endl;
	}
}