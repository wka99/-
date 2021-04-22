#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[20001];
int visited[20001] = { 0, };
int dist[20001] = { 0, };
int maxval = 0;

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	visited[idx] = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < v[top].size(); i++) {
			int curr = v[top][i];
			if (!visited[curr]) {
				dist[curr] = dist[top] + 1;
				if (maxval < dist[curr]) maxval = dist[curr];
				q.push(curr);
				visited[curr] = 1;
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int x, y;
	for (int i = 0; i < edge.size(); i++) {
		x = edge[i][0];
		y = edge[i][1];
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
	for (int i = 2; i <= n; i++) {
		if (maxval == dist[i])
			answer++;
	}
	return answer;
}
int main() {
	solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}
/*
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define MAX_N 20001

int visited[MAX_N];
vector<int> grph[MAX_N];
int depth[MAX_N];
int max_depth = 0;
void bfs(){
	queue<pair<int,int>>q;
	q.push({1,0});
	visited[1]=1;
	depth[0]++;
	while(!q.empty()){
		int f = q.front().first;
		int d = q.front(). second;
		max_depth = max(max_depth, d);
		q.pop();
		for(int i=0;i<grph[f].size();i++){
			int curr = grph[f][i];
			if(visited[curr]) continue;
			visited[curr]=1;
			q.push({curr, d+1});
			depth[d+1]++;
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for(int i=0;i<edge.size();i++){
		int a = edge[i][0];
		int b = edge[i][1];
		grph[a].push_back(b);
		grph[b].push_back(a);
	}
	bfs();
	answer = depth[max_depth];
	return answer;
}
*/