#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 501
#define INF 5000001

int N, M;
vector<vector<int>> edge;
/*
underflow�� �߻��� �� �־� �ڷ����� long long���� �������־�� �Ѵ�
���� ����Ŭ�� �����ϰ� �Ǹ� ������ �ּҰ��� �����ϰ� �Ǹ�
cost�� �ּҰ��� -10000, N�� �ִ밪�� 500, E�� �ִ밪�� 6000���� 
�־��� ��� -10000*500*6000 = -30000000000 �̸� �̴� int�� ������ ����� �ȴ�.
���� long long�� ����ؾ� �ϸ� int���� ����� ���, overflow�� ����
���� ����Ŭ�� ������ underflow�� ���� -1��� �� �������� ���� �ִ� �Ÿ���
����ϴ� ��찡 �߻��� �� �ִ�.
*/
long long d[MAX_N]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> N >> M;
	//�Ÿ� �迭 �ʱ�ȭ
	for (int i = 2; i <= N; i++) d[i] = INF;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
		if (a == 1) d[b] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = edge[j][0];
			int to = edge[j][1];
			int cost = edge[j][2];
			if (d[from] == INF) continue;
			if (d[to] > d[from] + cost) {
				if (i == N) {
					cout << -1 << "\n";
					return 0;
				}
				else d[to] = d[from] + cost;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (d[i] == INF) cout << -1 << "\n";
		else cout << d[i] << "\n";
	}
}