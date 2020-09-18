#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>v(100, vector<int>(100, 0));
int visited[100] = { 0, };

void DFS(int e) {
	cout << e << " ";
	visited[e] = 1;
	for (int i = 0; i < v[e].size(); i++) {
		if (!visited[v[e][i]]) {
			DFS(v[e][i]);
		}
	}
}
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