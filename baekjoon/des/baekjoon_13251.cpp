#include <iostream>
using namespace std;
#define MAX 2501

int M, K;
int rocks[MAX];
double dp[MAX][MAX];

double solve(int f, int t) {
	if (dp[f][t] != 0) return dp[f][t];
	if (f == t || t == 0)return dp[f][t] = 1;
	if (t == 1) return dp[f][t] = f;
	dp[f][t] = solve(f - 1, t - 1) + solve(f - 1, t);
	return dp[f][t];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	int total = 0;
	for (int i = 0; i < M; i++) {
		cin >> rocks[i];
		total += rocks[i];
	}
	cin >> K;
	double a = 0, b;
	b = solve(total, K);
	for (int i = 0; i < M; i++) {
		if (rocks[i] >= K) a += solve(rocks[i], K);
	}
	cout << fixed;
	cout.precision(11);
	cout << a / b << endl;
}