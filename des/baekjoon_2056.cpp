#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int task[10001][101] = { 0, }; //작업간 선행 관계
int time[101] = { 0, }; //작업별 수행 시간
int leftw[101] = { 0, }; //작업별 남은 선행 작업들
queue <int> first; //선행 관계가 없는 작업들
int total = 0; //모든 작업을 완료하기 위한 최소 시간

void BFS() {
	for (int i = 1; i <= N; i++) {
		if (leftw[i] == 0) {
			first.push(i);
		}
	}
	/*
	int max = 0;
	while (!first.empty()) {
		int f = first.front();
		first.pop();
		for (int i = 1; i <= N; i++) {
			if (task[i][f] == 1) {
				task[i][f] = 0;
				leftw[i]--;
			}
		}
	}*/
}
int main() {
	cin >> N;
	int j;
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> j;
		leftw[i] = j;
		for (; j > 0; j--) {
			cin >> tmp;
			task[i][tmp] = 1;
		}
	}
	BFS();
}