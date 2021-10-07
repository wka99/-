#include <iostream>
using namespace std;
#define MAX 16

int dp[MAX];//x일까지 얻을 수 있는 최대 수입
int N;
int main() {
	int t, p;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t >> p;
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + t - 1 <= N) dp[i + t - 1] = max(dp[i + t - 1], dp[i - 1] + p);
	}
	cout << dp[N] << endl;
}