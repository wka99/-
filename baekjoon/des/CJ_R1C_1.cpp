#include <iostream>
#include <vector>
using namespace std;
#define MAX_K 100000001

vector<int> selected;
vector<int> mine;
int T, N, K;
double ans = 0;
void dfs(int cnt) {
	if (cnt == 2) {
		int sdist = K;
		int mdist = K;
		double cnt = 0;
		for (int i = 1; i <= K; i++) { //´çÃ· ¹øÈ£
			for (int j = 0; j < selected.size(); j++) {
				sdist = min(sdist, abs(i - selected[j]));
			}
			for (int j = 0; j < mine.size(); j++) {
				mdist = min(mdist, abs(i - mine[j]));
			}
			if (mdist < sdist) cnt++;
			mdist = K; sdist = K;
		}
		ans = max(ans, cnt / K);
		return;
	}
	for (int i = 1; i <= K; i++) {
		mine.push_back(i);
		dfs(cnt + 1);
		mine.pop_back();
	}
}
int main() {
	cin >> T;
	int p;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		selected.clear(); mine.clear();
		for (int j = 0; j < N; j++) {
			cin >> p;
			selected.push_back(p);
		}
		dfs(0);
		cout << "Case #" << i << ": " <<ans<< endl;
		ans = 0;
	}
}