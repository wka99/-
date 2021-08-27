#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Greedy 알고리즘
//서류 점수 순으로 정렬하면 서류 점수가 1등인 지원자는 무조건 선발되며 다음 순위의 지원자는 선발된 지원자보다 서류 점수가 낮으므로
//선발되기 위해서는 면접 성적이 선발된 지원자보다 높아야 한다.

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