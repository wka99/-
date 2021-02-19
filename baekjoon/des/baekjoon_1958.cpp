#include <iostream>
#include <string>
using namespace std;
#define MAX 101

int dp[MAX][MAX][MAX];

int main() {
	string a, b, c;
	int maxV = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			for (int k = 1; k <= c.length(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
				if (maxV < dp[i][j][k]) maxV = dp[i][j][k];
			}
		}
	}
	cout << maxV << endl;
}