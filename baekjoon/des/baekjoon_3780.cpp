#include <iostream>
using namespace std;
#define MAX 20001

int T, N;
int par[MAX];
int dist[MAX];

int Find(int x) {
	if (x == par[x])return x;
	int xp = Find(par[x]);
	dist[x] += dist[par[x]];
	return par[x] = xp;
}
void Union(int i, int j) { //���� i�� ��� j�� ����
	par[i] = j;
	dist[i] = abs(i - j) % 1000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char cmd;
	int i, j;
	cin >> T;
	for (int test = 0; test < T; test++) {
		cin >> N;
		for (int idx = 0; idx <= N; idx++) {
			par[idx] = idx;
			dist[idx] = 0;
		}
		while (1) {
			cin >> cmd;
			if (cmd == 'O') break;
			if (cmd == 'E') { //���ͱ����� �Ÿ� ���
				cin >> i;
				Find(i);
				cout << dist[i] << "\n";
			}
			else { //���� i�� ��� j�� ����
				cin >> i >> j;
				Union(i, j);
			}
		}
	}
}