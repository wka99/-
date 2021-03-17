#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF 10000
//�÷��̵� ���� �˰����� ����Ͽ� ��� ���� ������ ��θ� �ľ�

int N, M;
int d[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b] = 1;//��� ����
	}
	//�÷��̵� �ͼ�
	for (int k = 1; k <= N; k++) { //�߰�
		for (int i = 1; i <= N; i++) { //���
			for (int j = 1; j <= N; j++) { //����
				if (d[i][k] && d[k][j])
					d[i][j] = 1;
			}
		}
	}
	int j, ans = 0;
	for (int i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (!d[j][i] && !d[i][j] && i != j) break;
		}
		if (j == N + 1) ans++;
	}
	cout << ans << endl;
}