#include <iostream>
#include <vector>
using namespace std;
#define MAX 51

int N, M, r, c, d;
int map[MAX][MAX];
int dx[4] = { -1,0,1,0 }; //�ϵ�����
int dy[4] = { 0,1,0,-1 };
int ans = 0;//û�� ������ ����

bool search(int x, int y, int cnt) {
	if (cnt == 4) return 0;//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ��
	d = (d - 1 + 4) % 4; //ȸ��
	int mx = x + dx[d];
	int my = y + dy[d];
	if (mx < 0 || my < 0 || mx >= N || my >= M || map[mx][my] == 1) {//û�� ���� ����
		return search(x, y, cnt + 1);
	}
	if (map[mx][my] == 2) {//û�� ���� ���� (�̹� û�� �Ϸ� or ��)
		return search(x, y, cnt+1);
	}
	r = mx; c = my;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		if (map[r][c] != 2) {
			map[r][c] = 2; //���� ��ġ û��
			ans++;
		}
		if (!search(r, c, 0)) { //2�� ����
			int tmp_r = r - dx[d];
			int tmp_c = c - dy[d];
			if (tmp_r < 0 || tmp_c < 0 || tmp_r >= N || tmp_c >= M) break;
			if (map[tmp_r][tmp_c] == 1) break; //���̶� ���� �Ұ���
			r = tmp_r; c = tmp_c; //����
			search(r, c, 0); //2������ ���ư�
		}
	}
	cout << ans << '\n';
}