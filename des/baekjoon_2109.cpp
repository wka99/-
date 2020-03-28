#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;//강연 요청 대학수
vector <pair<int, int>> dp;
vector <pair<int, int>> temp;

int greedy() {
	int sum = 0;
	sort(dp.begin(), dp.end());
	for (int i = 0; i < n; i++) {
		sum += dp[i].second;
		temp.push_back(make_pair(dp[i].second, dp[i].first));
		if (temp.size() > dp[i].first) {
			sort(temp.begin(), temp.end());
			sum -= temp[0].first;
			temp.erase(temp.begin());
		}
	}
	return sum;
}
int main() {
	cin >> n;
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		dp.push_back(make_pair(d, p));
	}
	cout << greedy() << endl;
}