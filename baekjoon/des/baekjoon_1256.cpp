#include <iostream>
#include <string>
using namespace std;
#define MAX_N 101
#define MAX 1000000000

string ans = "";
int dp[MAX_N][MAX_N];
int tn, tm;
int N, M, K;

// dp[x][y] a가 x개 b가 y개 있을 때 만들 수 있는 수열의 개수
// => x+yCy와 같다

void getWord(int a, int z, int left) {
	if (a == 0) {
		for (int i = 0; i < z; i++) ans += 'z';
		return;
	}
	if (z == 0) {
		for (int i = 0; i < a; i++) ans += 'a';
		return;
	}
	int skip = dp[a - 1][z];
	if (left < skip) {
		ans += 'a';
		getWord(a - 1, z, left);
	}
	else {
		ans += 'z';
		getWord(a, z - 1, left - skip);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//N개의 a와 M개의 z로 이루어진 문자열
	//사전순 K번째 문자열 출력
	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++) dp[i][0] = 1;
	for (int i = 0; i <= M; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1], MAX);
		}
	}
	if (dp[N][M] < K) cout << -1 << endl;
	else {
		getWord(N, M, K - 1);
		cout << ans << endl;
	}
}