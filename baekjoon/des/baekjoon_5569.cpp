#include <iostream>
using namespace std;
#define MAX 101
#define MOD 100000

int dp[MAX][MAX][2][2];

int main() {
	int w, h;
	cin >> w >> h;
	for (int i = 2; i <= h; i++)
		dp[i][1][0][0] = 1;
	for (int i = 2; i <= w; i++)
		dp[1][i][0][1] = 1;
	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % MOD;
			dp[i][j][0][1] = (dp[i][j - 1][0][1] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][0] = dp[i - 1][j][0][1] % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0] % MOD;
		}
	}
	int ans = (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD;
	cout << ans << endl;
}