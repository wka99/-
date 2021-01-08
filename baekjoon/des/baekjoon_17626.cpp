#include <iostream>
#include <cmath>
using namespace std;

int dp[50001] = {0,1,2,3,1,};
int n;

int findSqrtN(int x) {
	int sqn, min = 5, tmp;
	sqn = floor(sqrt(x));
	if (dp[x]) return dp[x];
	else if (sqn*sqn == x) {
		dp[x] = 1;
		return dp[x];
	}
	else {
		for (int i = sqn-1; i >= 1; i--) {
			tmp = findSqrtN(i*i) + findSqrtN(x - i*i);
			if (min > tmp) min = tmp;
		}
		dp[x] = min;
		return dp[x];
	}
}
int main() {
	cin >> n;
	cout << findSqrtN(n) << endl;
}