#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 101

int N, M;
int byte[MAX_N], cost[MAX_N];
int dp[MAX_N][MAX_N * MAX_N]; 
//dp[x][y] x번째 앱까지 y의 cost로 만들 수 있는 최대 byte?

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> byte[i];
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i - 1][j - cost[i]] + byte[i], dp[i - 1][j]);
			}
			else {

			}
		}
	}

}