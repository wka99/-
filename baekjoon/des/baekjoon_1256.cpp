#include <iostream>
#include <string>
using namespace std;
#define MAX 101
#define MAX_K 1000000000

int N, M, K;
int dp[MAX][MAX];
string ans = "";

// dp[n][m] => n+m C m = n+m-1 C m-1 + n+m-1 C m
// dp[n][m] = dp[n][m-1] + dp[n-1][m]

void getWord(int a, int z, int k) {
	if (a == 0) {
		for (int i = 0; i < z; i++) ans += 'z';
		return;
	}
	if (z == 0) {
		for (int i = 0; i < a; i++) ans += 'a';
		return;
	}
	int skip = dp[a - 1][z];
	if (skip < k) {
		ans += 'z';
		getWord(a, z - 1, k - skip);
	}
	else {
		ans += 'a';
		getWord(a - 1, z, k);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) dp[i][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = min(dp[i][j - 1] + dp[i - 1][j], MAX_K);
		}
	}
	if (dp[N][M] < K) cout << -1 << endl;
	else {
		getWord(N, M, K);
		cout << ans << endl;
	}
}