#include <iostream>
using namespace std;

int N, M;
int ans[9];
int visited[9];

void backtracking(int idx) {
	if (idx == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << ans[i] << " ";
		}cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (ans[idx - 1] <= i) {
			ans[idx] = i;
			backtracking(idx + 1);
		}
	}
}
int main() {
	cin >> N >> M;
	backtracking(1);
}
