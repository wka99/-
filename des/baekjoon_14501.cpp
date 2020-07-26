#include <iostream>
#include <algorithm>
using namespace std;

/*
각각의 날에 최대로 벌 수 있는 값을 구하면
최대 수익을 구할 수 있음
따라서 brute force 문제가 아닌 dp 문제
상담을 하는 경우와 상담을 하지 않는 경우를
모두 구해 최댓값을 구할 수 있도록 해야함
*/

int N;
int T[17] = { 0, };
int P[17] = { 0, };
int DP[17] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
		}
		DP[i + 1] = max(DP[i], DP[i + 1]);
	}
	cout << DP[N + 1] << endl;
} 