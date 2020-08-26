#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//문제집 (위상정렬)
int N, M;
int degree[32001] = { 0, };
vector <int> quiz[32001];
priority_queue <int, vector<int>, greater<int>> tmp;
int arr[320001];

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			tmp.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (tmp.empty())
			return;
		int x = tmp.top();
		cout << x << " ";
		tmp.pop();
		for (int j = 0; j < quiz[x].size(); j++) {
			if (--degree[quiz[x][j]] == 0) {
				tmp.push(quiz[x][j]);
			}
		}
	}cout << "\n";
}
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		degree[b]++;
		quiz[a].push_back(b);
	}
	topologySort();
}