#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 9
#define MAX 10001

int nos[MAX_N];
int ans[MAX_N], visited[MAX];
int N, M;

void backtracking(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[nos[i]]) {
			visited[nos[i]] = 1;
			ans[idx] = nos[i];
			backtracking(idx + 1);
			visited[nos[i]] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> nos[i];
	sort(nos, nos + N);
	backtracking(0);
}