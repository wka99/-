#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<float, int>a, pair<float, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	float users[501] = { 0, };
	vector<pair<float, int>> result;
	int m = 0;
	for (int i = 0; i < stages.size(); i++) {
		m = max(stages[i], m);
		for (int j = 0; j < stages[i]; j++) {
			users[j]++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i + 1 <= m) {
			float fail = (users[i] - users[i + 1]) / users[i];
			result.push_back({ fail, i + 1 });
		}
		else {
			result.push_back({ 0, i + 1 });
		}
	}
	sort(result.begin(), result.end(), cmp);
	for (int i = 0; i < N; i++) {
		answer.push_back(result[i].second);
	}
	return answer;
}
int main() {
	int N = 6;
	int N2 = 4;
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
	vector<int> stages2 = { 4,4,4,4,4 };
	solution(N, stages);
	solution(N2, stages2);
}