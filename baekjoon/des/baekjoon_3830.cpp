#include <iostream>
using namespace std;
#define MAX_N 100001

int p[MAX_N]; //�� ���Ұ� ���� ������ ��ǥ�� ǥ��
int d[MAX_N]; //���� ���� ����
int r[MAX_N]; //Ʈ���� rank�� ����, ��Ʈ ��常 �ش� Ʈ���� ���� ������ ���� ���� 1�� ���� ����
/*
	union tree�� ũ�⸦ ������ �ִ� �迭
	�ΰ��� Ʈ���� ��ġ�� ��� ũ�Ⱑ ū Ʈ���� ũ�Ⱑ ����
	Ʈ���� ��ġ�� ���� ����, find ������ ������ ��
	�θ� ���� Ƚ���� �������Ƿ� ȿ�����̰� �ȴ�.
	�ð����⵵�� ���̰� ����ȭ�� ���� �ʿ��� �迭
	7 9
	! 1 2 100
	! 2 3 100
	! 4 3 150
	! 6 7 50
	! 5 6 50
	! 5 4 10
	? 5 3
	? 5 7
	? 1 5
	0 0

	ans
	160
	100
	40
*/
int Find(int x) {
	if (x == p[x])return p[x];
	int xp = Find(p[x]);
	d[x] += d[p[x]];
	//update�� ��ǥ���� dist�� ����Ǿ��� ������ find �Լ��� �����ϸ鼭 
	//�θ� ����� dist���� ���ؼ� �ش� ��� x�� dist�� �������־�� ��
	return p[x] = xp;
}
void Union(int x, int y, int w) {
	int xp = Find(x);
	int yp = Find(y);
	if (xp == yp) return;
	//ū ������ ���� ������ ������
	if (r[xp] > r[yp]) {
		p[yp] = xp;
		d[yp] -= (d[y] - d[x] - w); // �ٿ����� �� Ʈ���� ��ǥ�� dist ����
		r[xp] += r[yp];
		r[yp] = 1;
	}
	else {
		p[xp] = yp;
		d[xp] += (d[y] - d[x] - w);
		r[yp] += r[xp];
		r[xp] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	char c;
	int a, b, w;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			p[i] = i; d[i] = 0; r[i] = 1;
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
				else
					cout << "UNKNOWN\n";
			}
		}
	}
}