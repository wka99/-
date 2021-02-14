#include <iostream>
using namespace std;
#define MAX_N 1025

int nums[MAX_N][MAX_N] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int x1, y1, x2, y2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nums[i][j];
			nums[i][j] += nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << nums[x2][y2] - nums[x1-1][y2] - nums[x2][y1-1] + nums[x1-1][y1-1]<< "\n";
	}
}