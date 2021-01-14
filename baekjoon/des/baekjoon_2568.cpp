#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> lines;
vector<int> install;
int idx[100001];
/*
lines의 각 원소들이 install의 어디에 들어가게 되는지를 기록하는 배열 idx
ex) lines = {1,3,4,2,5}
	install = {1,2,4,5}
	idx = {0,1,2,1,3}
	올바른 LIS 는 {1,3,4,5}로 install는 엉뚱한 결과
	LIS의 요소가 아닌 것을 찾기 위해서는 배열 idx에서
	오름차순을 해치는 요소들을 찾아야함
	=> 이는 lines 배열에서 뒤쪽에 위치하는 숫자이지만
	이분탐색에 의해 잘못 위치하게 된 숫자를 의미한다.
*/
vector<int> removed;
int N, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		lines.push_back({ a,b });
	}
	sort(lines.begin(), lines.end());
	install.push_back(lines[0].second);
	idx[0] = 0;
	vector<int>::iterator it;
	for (int i = 1; i < N; i++) {
		if (install.back() < lines[i].second) {
			install.push_back(lines[i].second);
			idx[i] = install.size() - 1;
		}
		else {
			it = lower_bound(install.begin(), install.end(), lines[i].second);
			*it = lines[i].second;
			idx[i] = it - install.begin();
		}
	}
	cout << N - install.size() << "\n";
	int cnt = install.size();
	cnt--;
	for (int i = N - 1; i >= 0; i--) {
		if (cnt == idx[i]) cnt--;
		else {
			removed.push_back(lines[i].first);
		}
	}
	for (int i = removed.size() - 1; i >= 0; i--) {
		cout << removed[i] << "\n";
	}
}