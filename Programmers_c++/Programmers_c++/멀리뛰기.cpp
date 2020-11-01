#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
dp 문제
n=1인 경우, 1
n=2인 경우, 2
n=3인 경우, 3
n=4인 경우, 4
따라서 dp[n] = dp[n-1] + dp[n-2]의 점화식을 얻을 수 있음
*/
/*dfs로 해결 가능하나 너무 많은 시간이 걸림
answer의 type이 long long인 거로 봐서
dfs로 해결하기에는 너무 큰 경우의 수*/

long long solution(int n) {
	long long answer = 0;
	long long dp[2001] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
	}
	answer = dp[n];
	return answer;
}