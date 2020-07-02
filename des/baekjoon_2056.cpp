#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//위상 정렬

int N;
vector <int> task[10001]; //작업간 선행 관계
int time[10001] = { 0, }; //작업별 수행 시간
int degree[10001] = { 0, }; //작업별 남은 선행 작업 개수 (진입 차수)
queue <int> first; //선행 관계가 없는 작업들
int total = 0; //모든 작업을 완료하기 위한 최소 시간
int d[10001] = { 0, };

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			first.push(i);
			d[i] = time[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (first.empty())
			break;
		int x = first.front();
		first.pop();
		for (int j = 0; j < task[x].size(); j++) {
			d[task[x][j]] = max(d[task[x][j]], d[x] + time[task[x][j]]);
			if (--degree[task[x][j]] == 0) {
				first.push(task[x][j]);
			}
		}
	}
}
int main() {
	cin >> N;
	int j;
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> j;
		degree[i] = j;
		for (; j > 0; j--) {
			cin >> tmp;
			task[tmp].push_back(i);
		}
	}
	topologySort();
	cout << *max_element(d, d + N + 1) << endl;
}