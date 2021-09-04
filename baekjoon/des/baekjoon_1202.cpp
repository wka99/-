#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector <pair<int, int>> jewel; //���� ���� (����, ����)
vector<int> bag;//���� ����
priority_queue<int> pq; //���� ���濡 ���� �� �ִ� ����
//���濡 ���� �� �ִ� ���� �� ���� ��� �� ���� ��
long long ans = 0;

void greedy() {
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && bag[i] >= jewel[idx].first) {
			pq.push(jewel[idx].second);
			idx++;
		}
		//���� ���濡 �� �� �ִ� ������ ū ���濡�� ���� �� ����
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
}
int main() {
	int cost, weight, b;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> weight >> cost;
		jewel.push_back({ weight, cost });
	}
	for (int i = 0; i < K; i++) {
		cin >> b;
		bag.push_back(b);
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	greedy();
	cout << ans << endl;
}