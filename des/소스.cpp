#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int N, K;
pair <int, int> jewel[MAX];
int bag[MAX];
priority_queue <int> tmp;
long long value = 0;

void greedy() {
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N&&bag[i] >= jewel[idx].first) {
			tmp.push(jewel[idx++].second);//조건 만족시 priority_queue에 다 넣고
		}
		if (!tmp.empty()) {
			value += tmp.top();//큐에서 가장 큰 값을 뽑아서 더하기
			tmp.pop();
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int j = 0; j < K; j++) {
		cin >> bag[j];
	}
	sort(jewel, jewel + N);
	//sort(bag, bag + K);
	greedy();
	cout << value << endl;
}