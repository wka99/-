#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF INT32_MAX

int N, r, c;
pair<int, int>mat[MAX_N];
int dp[MAX_N][MAX_N];

int mult(int from, int to) {
	int res = INF;
	if (dp[from][to] != -1) return dp[from][to];
	if (to == from) return dp[from][to] = 0;
	else {
		for (int i = from; i < to; i++) {
			int cur = mult(from, i) + mult(i + 1, to) + mat[from].first * mat[i].second * mat[to].second;
			if (res > cur)res = cur;
		}
	}
	return dp[from][to] = res;
}
int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		mat[i] = { r,c };
	}
	cout << mult(0, N - 1) << endl;
}