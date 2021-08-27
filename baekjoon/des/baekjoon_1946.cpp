#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Greedy �˰���
//���� ���� ������ �����ϸ� ���� ������ 1���� �����ڴ� ������ ���ߵǸ� ���� ������ �����ڴ� ���ߵ� �����ں��� ���� ������ �����Ƿ�
//���ߵǱ� ���ؼ��� ���� ������ ���ߵ� �����ں��� ���ƾ� �Ѵ�.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<pair<int, int>> scores;
		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			scores.push_back({ a,b });
		}
		sort(scores.begin(), scores.end());
		int count = 1;
		int tmp = scores[0].second;
		for (int j = 1; j < N; j++) {
			if (tmp > scores[j].second) {
				tmp = scores[j].second;
				count++;
			}
		}
		cout << count << '\n';
	}
}