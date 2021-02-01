#include <iostream>
using namespace std;
#define MAX_N 100001

int par[MAX_N]; //�� ���Ұ� ���� ������ ��ǥ�� ǥ��
int d[MAX_N]; //���� ���� ����
int r[MAX_N];
/*
	union tree�� ũ�⸦ ������ �ִ� �迭
	�ΰ��� Ʈ���� ��ġ�� ��� ũ�Ⱑ ū Ʈ���� ũ�Ⱑ ���� 
	Ʈ���� ��ġ�� ���� ����, find ������ ������ ��
	�θ� ���� Ƚ���� �������Ƿ� ȿ�����̰� �ȴ�.
	�ð����⵵�� ���̰� ����ȭ�� ���� �ʿ��� �迭
*/

int Find(int x) {
	if (par[x] == x) return par[x];
	int xp = Find(par[x]);
	d[x] += d[par[x]];
	return par[x] = xp;
}
void Union(int x, int y, int w) { //y�� x���� w ���ſ�
	int xp = Find(x);
	int yp = Find(y);
	//ū Ʈ���� ���� Ʈ�� ���̱�
	if (r[xp] > r[yp]) { //ū Ʈ�� xp, ���� Ʈ�� yp
		par[yp] = xp;
		d[yp] -= (d[y] - d[x] - w);
		r[xp] += r[yp];
		r[yp] = 1; //��ǥ�� ��尡 �ƴ� ��� ��� 1
	}
	else {
		par[xp] = yp;
		d[xp] += (d[y] - d[x] - w);
		r[yp] += r[xp];
		r[xp] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	char c;
	int a, b, w;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			par[i] = i; d[i] = 0; r[i] = 1;
		}
		for (int i = 0; i < M; i++) {
			cin >> c;
			if (c == '!') { //���� ����
				cin >> a >> b >> w;
				Union(a, b, w);
			}
			else { //������ ����
				cin >> a >> b;
				if (Find(a) == Find(b)) {
					cout << d[b] - d[a] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}
}