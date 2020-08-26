#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//�Ŷ�� & Greedy Algorithm

int N = 0;//������ ��
vector <pair<int, int>> task;
priority_queue <int> temp;//sort ��� priority queue�� ����Ͽ� �ð� �ʰ��� ����
int sum = 0;//�ִ� �Ŷ�� ��

void greedy() {
	sort(task.begin(), task.end());//������� �������� ����
	for (int i = 0; i < N; i++) {
		sum += task[i].second;
		temp.push(-task[i].second);
		if (temp.size() > task[i].first) {
			sum += temp.top();
			temp.pop();
		}
	}
}
int main() {
	cin >> N;
	int dead = 0;
	int ramen = 0;
	for (int i = 0; i < N; i++) {
		cin >> dead >> ramen;
		task.push_back(make_pair(dead, ramen));
	}
	greedy();
	cout << sum << endl;
}