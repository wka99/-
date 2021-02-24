#include <iostream>
using namespace std;
#define MAX_N 101
#define MAX_M 10000001

int N, M;
int dp[MAX_N*MAX_N];
int bytes[MAX_N], cost[MAX_N];
int minV = 10001, sum = 0;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> bytes[i];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = sum; j >=cost[i]; j--) {
			//해당 cost j로 얻을 수 있는 최대 byte 수
			dp[j] = max(dp[j], dp[j - cost[i]] + bytes[i]);
			if (dp[j] >= M) minV = min(minV, j);
		}
	}
	cout << minV << endl;
}