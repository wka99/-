#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//컵라면 & Greedy Algorithm

int N = 0;//숙제의 수
vector <pair<int, int>> task;
priority_queue <int> temp;//sort 대신 priority queue를 사용하여 시간 초과를 막음
int sum = 0;//최대 컵라면 수

void greedy() {
	sort(task.begin(), task.end());//데드라인 기준으로 정렬
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