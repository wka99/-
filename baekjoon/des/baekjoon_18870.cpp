#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, x;
	vector<int> ans(1000000, 0);
	vector<pair<int,int>> xs;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		xs.push_back({ x,i });
	}
	sort(xs.begin(), xs.end());
	for (int i = 1; i < N; i++) {
		if (xs[i - 1].first < xs[i].first) {
			ans[xs[i].second] = ans[xs[i - 1].second] + 1;
		}
		else ans[xs[i].second] = ans[xs[i - 1].second];
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}cout << endl;
}