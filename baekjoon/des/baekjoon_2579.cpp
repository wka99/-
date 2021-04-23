#include <iostream>
using namespace std;
#define MAX_N 301

int stair[MAX_N];
//dp[x][0] => x번째 계단을 연속 1번 밟은 경우 최대값
//dp[x][1]=> x번째 계단을 연속 2번 밟은 경우 최대값
int dp[MAX_N][2] = { 0, }; //dp[x][1]=> 2개 연속

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}
	dp[0][0] = stair[0]; dp[0][1] = stair[0];
	dp[1][0] = stair[1]; dp[1][1] = stair[1] + stair[0];
	for (int i = 2; i < N; i++) {
		dp[i][0] = stair[i] + max(dp[i - 2][0], dp[i - 2][1]);
		dp[i][1] = stair[i] + dp[i - 1][0];
	}
	cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
}