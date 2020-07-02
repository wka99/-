#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//���� ����

int N;
vector <int> task[10001]; //�۾��� ���� ����
int time[10001] = { 0, }; //�۾��� ���� �ð�
int degree[10001] = { 0, }; //�۾��� ���� ���� �۾� ���� (���� ����)
queue <int> first; //���� ���谡 ���� �۾���
int total = 0; //��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð�
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