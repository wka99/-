#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 501
#define INF 50000001

int N;
int build[MAX_N]; //짓는데 걸리는 시간
vector<int> grph[MAX_N];
int indeg[MAX_N];
int result[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x;
	cin >> N;
	int idx = 1;
	vector<int> tmp;
	while(idx <= N) {
		cin >> x;
		if (x == -1) {
			build[idx] = tmp[0];
			for (int i = 1; i < tmp.size(); i++) {
				grph[tmp[i]].push_back(idx);
				indeg[idx]++;
			}
			idx++;
			tmp.clear();
		}
		else tmp.push_back(x);
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indeg[i]) {
			q.push(i);
			result[i] = build[i];
		}
	}
	int time = 0, t, curr;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int i = 0; i < grph[t].size(); i++) {
			curr = grph[t][i];
			result[curr] = max(result[t] + build[curr], result[curr]);
			indeg[curr]--;
			if (!indeg[curr]) q.push(curr);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}
}