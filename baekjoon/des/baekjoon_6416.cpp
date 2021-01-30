#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int, int> outs, edges;
int check() {
	int nodes = 0;
	queue<int> q;
	map<int, int>::iterator it;
	for (it = outs.begin(); it != outs.end(); it++) {
		if (it->second == 0) q.push(it->first);
	}
	while (!q.empty()) {
		int x = q.front();
		nodes++;
		q.pop();
		outs[edges[x]]--;
		if (outs[edges[x]] == 0)
			q.push(edges[x]);
	}
	return nodes;
}
int main() {
	int u, v, cases = 1, e = 0;
	while (1) {
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		else if (u == 0 && v == 0) {
			if (e == 0 || check() == e + 1) {
				cout << "Case " << cases << " is a tree.\n";
			}
			else {
				cout << "Case " << cases << " is not a tree.\n";
			}
			outs.clear();
			edges.clear();
			cases++;
			e = 0;
		}
		else {
			e++;
			outs[u] += 1;
			if (outs.find(v) == outs.end())
				outs[v] = 0;
			edges[v] = u;
		}
	}
}