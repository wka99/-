#include <iostream>
using namespace std;
#define MAX_N 2001

int N;
int cake[MAX_N];
long long dp[MAX_N][MAX_N][2];

long long eatCake(int l, int r, int turn) {
	if (dp[l][r][turn]) return dp[l][r][turn];
	if (turn == 0) { //JOI±º
		if (l == r) return dp[l][r][turn] = cake[l];
		dp[l][r][turn] = max(eatCake((l + 1) % N, r, 1) + cake[l], eatCake(l, (r - 1 + N) % N, 1) + cake[r]);
	}
	else { //IOI¾ç
		if (l == r) return 0;
		if (cake[l] < cake[r]) {
			dp[l][r][turn] = eatCake(l, (r - 1 + N) % N, 0);
		}
		else dp[l][r][turn] = eatCake((l + 1) % N, r, 0);
	}
	return dp[l][r][turn];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cake[i];
	}
	long long res = 0;
	int l, r;
	for (int i = 0; i < N; i++) {
		l = (i + 1) % N;
		r = (i - 1 + N) % N;
		res = max(res, eatCake(l, r, 1) + cake[i]);
	}
	cout << res << endl;
}