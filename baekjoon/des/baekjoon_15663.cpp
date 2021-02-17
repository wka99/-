#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> nos;
int visited[9];
int N, M;
int ans[9];
void backtracking(int loc) {
	if (loc == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}cout << endl;
		return;
	}
	for (int i = 0; i < nos.size(); i++) {
		if (nos[i].second > 0) {
			nos[i].second--;
			ans[loc] = nos[i].first;
			backtracking(loc + 1);
			nos[i].second++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, j;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t;
		for (j = 0; j < nos.size(); j++) {
			if (nos[j].first == t) {
				nos[j].second++;
				break;
			}
		}
		if (j == nos.size())nos.push_back({ t,1 });
	}
	sort(nos.begin(), nos.end());
	backtracking(0);
}