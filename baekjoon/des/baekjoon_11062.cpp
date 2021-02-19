#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1001

int T, N;
int cards[MAX_N];
int dp[MAX_N][MAX_N][2];

int takeCard(int s, int e, int turn) {
	if (dp[s][e][turn] != 0)return dp[s][e][turn];
	if (turn == 0) { //근우
		if (s == e)return dp[s][e][turn] = cards[s];
		dp[s][e][turn] = max(takeCard(s + 1, e, 1) + cards[s], takeCard(s, e - 1, 1) + cards[e]);
	}
	else { //명우
		if (s == e) return 0;
		dp[s][e][turn] = min(takeCard(s + 1, e, 0), takeCard(s, e - 1, 0));
	}
	return dp[s][e][turn];
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> cards[j];
		}
		cout << takeCard(0, N - 1, 0) << endl;
		memset(dp, 0, sizeof(dp));
	}
}