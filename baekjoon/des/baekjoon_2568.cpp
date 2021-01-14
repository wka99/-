#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> lines;
vector<int> install;
int idx[100001];
/*
lines�� �� ���ҵ��� install�� ��� ���� �Ǵ����� ����ϴ� �迭 idx
ex) lines = {1,3,4,2,5}
	install = {1,2,4,5}
	idx = {0,1,2,1,3}
	�ùٸ� LIS �� {1,3,4,5}�� install�� ������ ���
	LIS�� ��Ұ� �ƴ� ���� ã�� ���ؼ��� �迭 idx����
	���������� ��ġ�� ��ҵ��� ã�ƾ���
	=> �̴� lines �迭���� ���ʿ� ��ġ�ϴ� ����������
	�̺�Ž���� ���� �߸� ��ġ�ϰ� �� ���ڸ� �ǹ��Ѵ�.
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