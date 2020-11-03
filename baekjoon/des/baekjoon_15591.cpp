#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	// p, q가 유사도 r을 가짐
	vector<pair<int, int>> vid[5001];
	int p, q, r;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> q >> r;
		vid[p].push_back({ r,q });
		vid[q].push_back({ r,p });
	}
	int k, v, cnt, curr;
	for (int i = 0; i < Q; i++) {
		cin >> k >> v;
		int visited[5001] = { 0, };
		queue<int> qu;
		cnt = 0;
		qu.push(v);
		visited[v] = 1;
		while (!qu.empty()) {
			curr = qu.front();
			qu.pop();
			for (int j = 0; j < vid[curr].size(); j++) {
				if (!visited[vid[curr][j].second]&&vid[curr][j].first >= k) {
					qu.push(vid[curr][j].second);
					visited[vid[curr][j].second] = 1;
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}