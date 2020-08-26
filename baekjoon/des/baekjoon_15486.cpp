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
		if (i + T[i] <= N+1) {//상담을 하는 경우
			DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
		}
		//상담을 하지 않는 경우
		DP[i + 1] = max(DP[i + 1], DP[i]);
	}
	cout << DP[N+1] << endl;
}