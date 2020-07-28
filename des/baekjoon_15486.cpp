#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[1500001] = { 0, };
int P[1500001] = { 0, };
int DP[1500001] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N+1) {//����� �ϴ� ���
			DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
		}
		//����� ���� �ʴ� ���
		DP[i + 1] = max(DP[i + 1], DP[i]);
	}
	cout << DP[N+1] << endl;
}