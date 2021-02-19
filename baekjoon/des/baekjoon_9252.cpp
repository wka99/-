#include <iostream>
#include <string>
using namespace std;
#define MAX 1001

int dp[MAX][MAX]; 
// dp[x][y] => 문자열 a를 x번째까지 문자열 b를 y번째까지 
// 확인했을 때 최장 공통 부분 수열의 길이 저장

int main() {
	string a, b;
	int maxV = 0;
	cin >> a >> b;
	if (a.length() > b.length()) swap(a, b);
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (maxV < dp[i][j]) maxV = dp[i][j];
		}
	}
	cout << maxV << endl;
	int i = a.length(), j = b.length();
	string ans = "";
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else if (dp[i][j] == dp[i - 1][j - 1]+1) {
			ans = a[i - 1] + ans;
			i--; j--;
		}
	}
	cout << ans << endl;
}