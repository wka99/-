#include <iostream>
using namespace std;
//합분해, 다이나믹 프로그래밍
int N, K;
int sum = 0;
long long DP[201][201] = {0, };

int main() {
	cin >> N >> K;
	for (int i = 1; i < 201; i++) {
		DP[0][i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1])%1000000000;
		}
	}
	cout << DP[N][K] << endl;
}