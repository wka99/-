#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
/*
	[트리]
	1. 노드가 0개
	2. 노드가 1개 이상
		2-1. 들어오는 간선은 반드시 1개 또는 0개여야 함
		2-2. 나가는 간선은 0개 이상일 수 있음

	노드에서 바깥으로 나가는 간선의 개수를 저장하는 outs와
	진입 간선을 나타내는 edges를 사용하여 트리인지 아닌지
	해당 여부를 확인할 수 있다.
	outs가 0인 노드를 지우고 해당 노드의 진입 간선을 확인하여
	간선의 끝에 위치한 노드의 outs를 1개 줄인다. 
	이 과정을 반복하여 트리의 노드를 모두 지울 수 있는 경우 => 트리
	지울 수 없는 경우 => 트리가 아니다.

	+ 노드의 범위 제한이 주어지지 않았으므로 자료구조 map을 사용한다
*/

map<int, int> outs; //각 노드의 진출 간선 수
map<int, int> edges;//진입 간선

int check() {
	int res = 0;
	queue<int> q;
	map<int, int>::iterator it;
	for (it = outs.begin(); it != outs.end(); it++) {
		if (it->second == 0) q.push(it->first);
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		outs[edges[f]]--;
		res++;
		if (outs[edges[f]] == 0) {
			q.push(edges[f]);
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int caseNum = 1;
	int u, v;
	int e = 0;
	while (1) {
		cin >> u >> v;
		if (u == -1 && v == -1)break;
		else if (u == 0 && v == 0) { //테스트 케이스
			if (e == 0 || e + 1 == check())
				cout << "Case " << caseNum << " is a tree.\n";
			else
				cout << "Case " << caseNum << " is not a tree.\n";
			e = 0; caseNum++;
			outs.clear();
			edges.clear();
		}
		else {
			outs[u] += 1;
			if (outs.find(v) == outs.end())
				outs[v] = 0;
			if (edges.find(v) == edges.end())
				edges.insert({ v, u });
			e++;
		}
	}
}