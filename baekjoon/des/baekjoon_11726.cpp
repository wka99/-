#include <iostream>
using namespace std;

int N;
int dp[1001] = { 1,1,2, };

int find(int x) {
	if (dp[x]) return dp[x];
	dp[x] = (find(x - 1) + find(x - 2)) % 10007;
	return dp[x];
}
int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[N] << endl;
}