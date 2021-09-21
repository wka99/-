#include <iostream>
using namespace std;
#define MAX 1001

int N, M;
int square[MAX][MAX];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	char c;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> c;
			square[i][j] = c - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (square[i][j]) {
				square[i][j] = min(square[i][j - 1], min(square[i - 1][j], square[i - 1][j - 1])) + 1;
				ans = max(square[i][j], ans);
			}
		}
	}
	cout << ans * ans << endl;
}