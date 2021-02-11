#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 101
//�Ҽ����� �� �� N��° ���� ���غ���
//priority queue�� �̿��ؾ���

long long num[MAX_N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int K, N;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	vector<int> answer;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> num[i];
		pq.push(num[i]);
	}
	for(int i = 0;i < N;i++){
		long long head = pq.top(); pq.pop();
		for (int j = 0; j < K; j++) {
			pq.push(head * num[j]);
			if (head % num[j] == 0) break;
		}
		answer.push_back(head);
	}
	cout << answer[N - 1] << "\n";
}