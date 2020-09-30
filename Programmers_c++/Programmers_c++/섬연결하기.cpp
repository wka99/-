#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Kruskal �˰���, Greedy �˰���

int roots[100];

int find(int x) {
	if (roots[x] == x) return x;
	else return find(roots[x]);
}
bool cmp(vector<int> &a, vector<int> &b) { //������ ����ġ�� �������� ����
	return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	sort(costs.begin(), costs.end(), cmp);
	for (int i = 0; i < n; i++) {//��Ʈ��� �ʱ�ȭ
		roots[i] = i;
	}
	int x, y, cost;
	for (int i = 0; i < costs.size(); i++) {
		x = find(costs[i][0]);
		y = find(costs[i][1]);
		cost = costs[i][2];
		if (x != y) {
			roots[x] = y;
			answer += costs[i][2];
		}
	}
	return answer;
}
int main() {
	cout<<solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});
}