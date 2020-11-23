#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��ȭ���� �������� ������ ����
/*
�� ������ ��� ����� ��ġ�� ���� �� ĭ�� ���� ������Ʈ�ϴ� ����� ���̰� ���� �ȴ�.
1. �ﰢ���� ���� ���� ��ġ
=> �밢�� ���� ��ҿ� ���� ĭ�� ���� ���� ��
2. �ﰢ���� ������ ���� ��ġ
=> �밢�� ���� ��ҿ� ���� ĭ�� ���� ���� ��
3. ���ο� ��ġ
=> ���� ����, ������ �� ��� �� �� ū ���� ���� ĭ�� ���� ���� ��
*/
int dp[501][501] = { 0, };
int solution(vector<vector<int>> triangle) {
	int answer = triangle[0][0];
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {//���� ��
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1) {//������ ��
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {//����
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