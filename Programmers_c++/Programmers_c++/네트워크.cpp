#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[201] = { 0, };

void DFS(vector<vector<int>> cpy, int idx) {
	for (int i = 0; i < cpy[idx].size(); i++) {
		if (!visited[i]) {
			if (cpy[idx][i] == 1 && i != idx) {
				visited[i] = 1;
				DFS(cpy, i);
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			DFS(computers, i);
			answer++;
		}
	}
	return answer;
}
int main() {
	cout<<solution(3, { {1, 1, 0},{1, 1, 0 }, {0, 0, 1}});
}