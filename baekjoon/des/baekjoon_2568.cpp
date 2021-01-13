#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, a, b;
	cin >> N;
	vector<pair<int, int>> lines;
	vector<int> install;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		lines.push_back({ a,b });
	}
	sort(lines.begin(), lines.end());
	install.push_back(lines[0].second);
	int cnt = 1;
	vector<int>::iterator it;
	for (int i = 1; i < N; i++) {
		it = lower_bound(install.begin(), install.end(), lines[i].second);
		if (it == install.end()) {
			install.push_back(lines[i].second);
		}
		else {
			*it = lines[i].second;
		}
	}
	cout << N-install.size() << endl;
}