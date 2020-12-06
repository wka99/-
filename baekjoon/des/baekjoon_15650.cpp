#include <iostream>
#include <vector>
using namespace std;

int visited[9] = { 0, };
int n, m;
void dfs(int idx, int cnt, vector<int> curr) {
	if (cnt == m) {
		for (int i = 0; i < curr.size(); i++) {
			cout << curr[i] << " ";
		}cout << endl;
		return;
	}
	for (int i = idx + 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			curr.push_back(i);
			dfs(i, cnt + 1, curr);
			visited[i] = 0;
			curr.pop_back();
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n - m + 1; i++) {
		dfs(i, 1, {i});
	}
}