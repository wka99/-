#include <iostream>
using namespace std;
#define MAX_N 2001

//점화식을 세우기 전
//어떤 조건에 따라 답이 달라지는지 생각해보자
long long dp[MAX_N][MAX_N][2];
int cake[MAX_N];
int N;

long long eatCake(int s, int e, int turn) {
	if (dp[s][e][turn] != 0) return dp[s][e][turn];
	if (turn == 0) { //JOI군
		if (s == e) return dp[s][e][turn] = cake[s];
		dp[s][e][turn] = max(eatCake(s, (e - 1 + N) % N, 1) + cake[e], eatCake((s + 1) % N, e, 1) + cake[s]);
	}
	else { //IOI양
		if (s == e)return 0;
		if (cake[s] < cake[e])
			dp[s][e][turn] = eatCake(s, (e - 1 + N) % N, 0);
		else
			dp[s][e][turn] = eatCake((s + 1) % N, e, 0);
	}
	return dp[s][e][turn];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cake[i];
	}
	int s, e;
	long long res = 0;
	for (int i = 0; i < N; i++) {
		s = (i + 1) % N;
		e = (i - 1 + N) % N;
		res = max(res,  eatCake(s, e, 1) + cake[i]);
	}
	cout << res << endl;
}