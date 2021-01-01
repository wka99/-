#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> grph[1001];
int check2[1001] = { 0, };
int cnt = 0;
void dfs(int n) {
	cnt++;
	cout << n;
	if (cnt < N)
		cout << " ";
	else cout << endl;
	check2[n] = 1;
	for (int i = 0; i < grph[n].size(); i++) {
		if(!check2[grph[n][i]])
			dfs(grph[n][i]);
	}
}
void bfs() {
	queue<int> q;
	int check[1001] = { 0, };
	int node;
	q.push(V);
	check[V] = 1;
	while (!q.empty()) {
		node = q.front();
		cout << node;
		cnt++;
		if (cnt < N)
			cout << " ";
		else cout << endl;
		q.pop();
		for (int i = 0; i < grph[node].size(); i++) {
			if (!check[grph[node][i]]) {
				q.push(grph[node][i]);
				check[grph[node][i]] = 1;
			}
		}
	}
	cout << endl;
}
int main() {
	int a, b;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		grph[a].push_back(b);
		grph[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++) {
		if (grph[i].size() > 0)
			sort(grph[i].begin(), grph[i].end());
	}
	dfs(V);
	cnt = 0;
	bfs();
}