#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
/*
	[Ʈ��]
	1. ��尡 0��
	2. ��尡 1�� �̻�
		2-1. ������ ������ �ݵ�� 1�� �Ǵ� 0������ ��
		2-2. ������ ������ 0�� �̻��� �� ����

	��忡�� �ٱ����� ������ ������ ������ �����ϴ� outs��
	���� ������ ��Ÿ���� edges�� ����Ͽ� Ʈ������ �ƴ���
	�ش� ���θ� Ȯ���� �� �ִ�.
	outs�� 0�� ��带 ����� �ش� ����� ���� ������ Ȯ���Ͽ�
	������ ���� ��ġ�� ����� outs�� 1�� ���δ�. 
	�� ������ �ݺ��Ͽ� Ʈ���� ��带 ��� ���� �� �ִ� ��� => Ʈ��
	���� �� ���� ��� => Ʈ���� �ƴϴ�.

	+ ����� ���� ������ �־����� �ʾ����Ƿ� �ڷᱸ�� map�� ����Ѵ�
*/

map<int, int> outs; //�� ����� ���� ���� ��
map<int, int> edges;//���� ����

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
		else if (u == 0 && v == 0) { //�׽�Ʈ ���̽�
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