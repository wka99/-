#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.second.first == b.second.first) return a.second.second < b.second.second;
	return a.second.first < b.second.first;
}
int main() {
	int N, choo, w;
	map<int, pair<int, int>> who;
	cin >> N >> choo;
	for (int i = 0; i < choo; i++) {
		cin >> w;
		if (who.find(w) == who.end()) { //등록이 안된 경우
			if (who.size() < N) {
				who[w].first += 1;
				who[w].second = i;
			}
			else { //표가 가장 적은 사람 제거
				vector<pair<int, pair<int, int>>> v(who.begin(), who.end());
				sort(v.begin(), v.end(), cmp);
				who.erase(who.find(v[0].first));
				who[w].first += 1;
				who[w].second = i;
			}
		}
		else { //등록이 되어있는 경우
			who[w].first += 1;
		}
	}
	for (auto it = who.begin(); it != who.end(); it++) {
		cout << it->first << " ";
	}cout << endl;
}