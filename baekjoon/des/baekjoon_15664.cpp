#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> nos;
int N, M;
int ans[9];

void backtracking(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}cout << endl;
		return;
	}
	for (int i = 0; i < nos.size(); i++) {
		if (nos[i].second > 0 && (idx == 0 || ans[idx-1] <= nos[i].first)) {
			nos[i].second--;
			ans[idx] = nos[i].first;
			backtracking(idx +1);
			nos[i].second++;
		}
	}
}
int main() {
	int t, j;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t;
		for (j = 0; j < nos.size(); j++) {
			if (t == nos[j].first) {
				nos[j].second++;
				break;
			}
		}
		if (j == nos.size())nos.push_back({ t,1 });
	}
	sort(nos.begin(), nos.end());
	backtracking(0);
}
