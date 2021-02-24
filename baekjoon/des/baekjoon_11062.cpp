#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1001

int dp[MAX_N][MAX_N][2]; //구간 dp => 근우 점수 저장
int cards[MAX_N];

int play(int l, int r, int turn) {
	if (dp[l][r][turn]) return dp[l][r][turn];
	if (turn == 0) { //근우 (선) => 자신의 점수가 최대가 되도록 해야함
		if (l == r)return dp[l][r][turn] = cards[l];
		dp[l][r][turn] = max(play(l + 1, r, 1) + cards[l], play(l, r - 1, 1) + cards[r]);
	}
	else { //명우 => 근우의 점수가 최소가 되도록 해야함
		if (l == r) return 0;
		dp[l][r][turn] = min(play(l + 1, r, 0), play(l, r - 1, 0));
	}
	return dp[l][r][turn];
}
int main() {
	int N, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> cards[j];
		}
		memset(dp, 0, sizeof(dp));
		cout << play(0, N - 1, 0) << endl;
	}
}