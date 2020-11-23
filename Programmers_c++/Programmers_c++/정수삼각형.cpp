#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//점화식을 세워보는 연습을 하자
/*
이 문제의 경우 요소의 위치에 따라 각 칸의 값을 업데이트하는 방법에 차이가 나게 된다.
1. 삼각형의 왼쪽 끝에 위치
=> 대각선 위의 요소에 현재 칸의 값을 더한 것
2. 삼각형의 오른쪽 끝에 위치
=> 대각선 위의 요소에 현재 칸의 값을 더한 것
3. 내부에 위치
=> 왼쪽 위와, 오른쪽 위 요소 중 더 큰 값과 현재 칸의 값을 더한 것
*/
int dp[501][501] = { 0, };
int solution(vector<vector<int>> triangle) {
	int answer = triangle[0][0];
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {//왼쪽 끝
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1) {//오른쪽 끝
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {//내부
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
			answer = max(answer, dp[i][j]);
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> triangle = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
	cout<<solution(triangle);
}