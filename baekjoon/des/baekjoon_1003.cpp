#include <iostream>
#include <vector>
using namespace std;

int dp[41] = { 1,1, };

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0)
			cout << "1 0" << endl;
		else if (N == 1)
			cout << "0 1" << endl;
		else {
			for (int j = 2; j <= N; j++) {
				if(!dp[j])
					dp[j] = dp[j - 1] + dp[j - 2];
			}
			cout << dp[N - 2] << " " << dp[N - 1] << endl;
		}
	}
}