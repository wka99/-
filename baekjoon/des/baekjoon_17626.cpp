#include <iostream>
#include <cmath>
using namespace std;

//다이나믹 프로그래밍 기법 사용하여 최소값 구하기

int dp[50001] = { 0,1,2,3,1, };

int findNum(int x) {
	int sqn = floor(sqrt(x));
	int minNum = 50001, tmp;
	if (dp[x]) return dp[x];
	if (x == sqn * sqn) { //한개의 제곱수로 나타낼 수 있는 경우
		dp[x] = 1;
		return dp[x];
	}
	else { //여러개의 제곱수로 나타내야 하는 경우
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