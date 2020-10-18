#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>v(100, vector<int>(100, 0));
int visited[100] = { 0, };

/*
깊이 우선 탐색
한 노드에서 시작하여 다음 분기(branch)로 넘어가기 전에
해당 분기(branch)를 완벽하게 탐색하는 방법
*/
void DFS(int e) {
	cout << e << " ";
	visited[e] = 1;
	for (int i = 0; i < v[e].size(); i++) {
		if (!visited[v[e][i]]) {
			DFS(v[e][i]);
		}
	}
}
/*
너비 우선 탐색
시작 정점으로부터 가까운 정점들을 먼저 탐색하고
먼 정점을 나중에 탐색하는 방법
*/
void BFS(int e) {
	queue<int>q;
	q.push(e);
	visited[e] = 1;
	while (!q.empty()) {
		int t = q.front();
		cout << t << " ";
		q.pop();
		for (int i = 0; i < v[t].size(); i++) {
			if (!visited[v[t][i]]) {
				q.push(v[t][i]);
				visited[v[t][i]] = 1;
			}
		}
	}
}

int main() {
	v[0].push_back(1);
	v[0].push_back(2);
	v[0].push_back(4);
	v[1].push_back(0);
	v[1].push_back(2);
	v[2].push_back(0);
	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);
	v[3].push_back(2);
	v[3].push_back(4);
	v[4].push_back(0);
	v[4].push_back(2);
	v[4].push_back(3);
	//DFS(0);
	cout << endl;
	BFS(0);
}