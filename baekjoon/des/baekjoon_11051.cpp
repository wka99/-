#include <iostream>
using namespace std;
#define MAX_N 1001
//nCk = n-1Ck-1 + n-1Ck 임을 이용

int dp[MAX_N][MAX_N];
int solve(int n, int k) {
	if (dp[n][k] != 0)return dp[n][k];
	if (n == k || k == 0) return dp[n][k] = 1;
	else if (k == 1) return dp[n][k] = n;
	dp[n][k] = (solve(n - 1, k - 1) + solve(n - 1, k)) % 10007;
	return dp[n][k];
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
}