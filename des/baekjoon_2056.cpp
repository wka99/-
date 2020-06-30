#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int task[10001][101] = { 0, }; //�۾��� ���� ����
int time[101] = { 0, }; //�۾��� ���� �ð�
int leftw[101] = { 0, }; //�۾��� ���� ���� �۾���
queue <int> first; //���� ���谡 ���� �۾���
int total = 0; //��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð�

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