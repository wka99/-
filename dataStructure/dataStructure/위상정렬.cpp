#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> degree = { 0,1,1,1,1,2 };
vector<int> v[6];

void topologySort(){
	queue<int> q;
	for (int i = 0; i < 6; i++) {
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int zero = q.front();
		cout << zero << endl;
		q.pop();
		for (int i = 0; i < v[zero].size(); i++) {
			if (--degree[v[zero][i]] == 0)
				q.push(v[zero][i]);
		}
	}
}
int main() {
	v[0].push_back(1);
	v[1].push_back(3);
	v[1].push_back(5);
	v[2].push_back(5);
	v[3].push_back(2);
	v[5].push_back(4);
	topologySort();
}