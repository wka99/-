#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector <pair<int, int>> jewel; //보석 정보 (가격, 무게)
vector<int> bag;//가방 정보
priority_queue<int> pq; //현재 가방에 넣을 수 있는 보석
//가방에 담을 수 있는 보석 중 가장 비싼 걸 골라야 함
long long ans = 0;

void greedy() {
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && bag[i] >= jewel[idx].first) {
			pq.push(jewel[idx].second);
			idx++;
		}
		//작은 가방에 들어갈 수 있는 보석은 큰 가방에도 넣을 수 있음
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