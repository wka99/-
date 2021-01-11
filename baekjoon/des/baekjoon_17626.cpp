#include <iostream>
#include <cmath>
using namespace std;

//���̳��� ���α׷��� ��� ����Ͽ� �ּҰ� ���ϱ�

int dp[50001] = { 0,1,2,3,1, };

int findNum(int x) {
	int sqn = floor(sqrt(x));
	int minNum = 50001, tmp;
	if (dp[x]) return dp[x];
	if (x == sqn * sqn) { //�Ѱ��� �������� ��Ÿ�� �� �ִ� ���
		dp[x] = 1;
		return dp[x];
	}
	else { //�������� �������� ��Ÿ���� �ϴ� ���
		for (int i = sqn; i > 0; i--) {
			tmp = findNum(i*i) + findNum(x - i * i);
			if (minNum > tmp) minNum = tmp;
		}
		dp[x] = minNum;
		return dp[x];
	}
}
int main() {
	int N;
	cin >> N;
	cout << findNum(N) << endl;
}