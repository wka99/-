#include <iostream>
#include <string>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];

int main() {
	string a, b;
	int maxV = 0;
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			maxV = max(maxV, dp[i][j]);
		}
	}
	cout << maxV << endl;
}