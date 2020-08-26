#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 300000;

int N = 0, K = 0;
pair<int, int> jewel[MAX];
int bag[MAX];
priority_queue <int> pq;
long long result = 0;

void greedy() {
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N&&jewel[idx].first <= bag[i]) {
			pq.push(jewel[idx++].second);
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(jewel, jewel+N);
	sort(bag, bag+K);
	greedy();
	cout << result << endl;
}