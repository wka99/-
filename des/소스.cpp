#include <iostream>
#include <queue>
using namespace std;
//���� ����
int N;
char map[101][101];
int check[101][101] = { 0, };//�湮 ����
int idx[4] = { -1,1,0,0 };//��, �Ʒ�
int idy[4] = { 0,0,-1,1 };//��, ��
queue <pair<int, int>> q;

void wrongBfs(int a, int b) {
	q.push(make_pair(a, b));
	int x, y;//���� ��ġ
	char rgb;//���� rgb
	int mx, my;//�̵� ������ ��ġ
	char mrgb; //�̵��� ���� rgb
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		check[x][y] = 1;
		q.pop();
		rgb = map[x][y];
		for (int i = 0; i < 4; i++) {
			mx = x + idx[i];
			my = y + idy[i];
			if (mx >= 0 && mx < N&&my >= 0 && my < N&&check[mx][my] == 0) {//���� ��&�湮 ���� Ȯ��
				mrgb = map[mx][my];
				if (rgb == mrgb) {//��ġ�ϴ� ��� �߰�
					q.push(make_pair(mx, my));
				}
			}
		}
	}
}
void bfs(int a, int b) {
	char rgb, nrgb;
	int nx, ny;//�̵���
	int mx, my;//�̵� ��
	q.push({ a,b });
	rgb = map[a][b];
	check[a][b] = 1;
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			mx = nx + idx[i];
			my = ny + idy[i];
			if (mx >= 0 && mx < N&&my>=0 && my < N) {//������
				if (check[mx][my] == 0&&map[mx][my]==map[nx][ny]) {//�湮������ ����
					q.push({ mx,my });
					check[mx][my] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {//���ϻ��� �ƴ�
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				wrongBfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	cnt = 0;
	for (int i = 0; i < N; i++) {//���ϻ���
		for (int j = 0; j < N; j++) {
			check[i][j] = 0;
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				wrongBfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}