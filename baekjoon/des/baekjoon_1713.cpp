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
/*
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int when[101]; //각 학생 추천받은 시기
int cnt[101]; //각 학생 득표수
int curr = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, s;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (cnt[s] == 0) { //사진첩에 없음
			if (curr < N) {
				when[s] = i;
				cnt[s] += 1;
				curr++;
			}
			else {
				int minC = 1001;
				int pops;
				for (int i = 1; i < 101; i++) {
					if (cnt[i] != 0 && minC > cnt[i]) {
						pops = i;
						minC = cnt[i];
					}
					else if (cnt[i] != 0 && minC == cnt[i]) {
						if (when[pops] > when[i]) {
							pops = i;
						}
					}
				}
				cnt[pops] = 0;
				when[pops] = 0;
				cnt[s] += 1;
				when[s] = i;
			}
		}
		else { //사진첩에 있음
			cnt[s] += 1;
		}
	}
	for (int i = 1; i < 101; i++) {
		if (cnt[i] != 0)cout << i << " ";
	}cout << endl;
}
*/