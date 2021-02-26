#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000001

int dp[MAX];
int before[MAX]; //Áß¿ä//

int findMin(int x) {
	if (x <= 1) {
		before[x] = -1;
		return dp[x] = 0;
	}
	if (dp[x] != -1) return dp[x];
	int tmp = MAX, next;
	if (x % 3 == 0) {
		next = findMin(x / 3) + 1;
		if (tmp > next) {
			tmp = next;
			before[x] = x / 3;
		}
	}
	if (x % 2 == 0) {
		next = findMin(x / 2) + 1;
		if (tmp > next) {
			tmp = next;
			before[x] = x / 2;
		}
	}
	next = findMin(x - 1) + 1;
	if (tmp > next) {
		tmp = next;
		before[x] = x - 1;
	}
	dp[x] = tmp;
	return dp[x];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x;
	cin >> x;
	memset(dp, -1, sizeof(dp));
	int cnt = findMin(x);
	cout << cnt << endl;
	int curr = x;
	while (curr != -1) {
		cout << curr << " ";
		curr = before[curr];
	}cout << endl;
}