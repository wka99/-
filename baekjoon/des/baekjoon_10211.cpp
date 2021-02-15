#include <iostream>
using namespace std;
#define MAX_N 1001

int num[MAX_N]; //´©ÀûÇÕ
int dp[MAX_N];
int main() {
	int N, T, maxv, maxidx;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int maxv = -1000001;
		for (int j = 1; j <= N; j++) {
			cin >> num[j];
		}
		for (int j = 1; j <= N; j++) {
			dp[j] = max(num[j] + dp[j - 1], num[j]);
			if (maxv < dp[j]) maxv = dp[j];
		}
		cout << maxv << endl;
	}
}