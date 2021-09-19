#include <iostream>
using namespace std;
#define MAX 1001

int N, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	int tmp;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int dp[MAX] = { 0, };
		int ans = -10000000;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			dp[i] = max(tmp, dp[i - 1] + tmp);
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
}