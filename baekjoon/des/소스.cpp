#include <iostream>
using namespace std;
#define MAX 2001

int N;
int A[MAX];
long long dp[MAX][MAX][2];//남은 케익의 범위가 x~y, 0: JOI, 1:IOI

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}