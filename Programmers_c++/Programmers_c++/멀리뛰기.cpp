#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
dp ����
n=1�� ���, 1
n=2�� ���, 2
n=3�� ���, 3
n=4�� ���, 4
���� dp[n] = dp[n-1] + dp[n-2]�� ��ȭ���� ���� �� ����
*/
/*dfs�� �ذ� �����ϳ� �ʹ� ���� �ð��� �ɸ�
answer�� type�� long long�� �ŷ� ����
dfs�� �ذ��ϱ⿡�� �ʹ� ū ����� ��*/

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