#include <iostream>
using namespace std;

int n = 0;//�볪�� �� ũ��
int map[500][500] = { 0, };//�볪�� �� ����
int di[4] = { 1,-1,0,0, };//��, ��
int dj[4] = { 0,0,-1,1 };//��, ��
int dp[500][500] = { 0, };//�� ��ġ���� �������� �� �Ǵٰ� �� �� �ִ� �ϼ��� ����
int k = 0;//�Ǵٰ� �ִ��� �� �� �ִ� �ϼ�

int max(int a, int b) { return a > b ? a : b; }//�� ū�� ��ȯ

int simulation(int x, int y) {
	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	dp[x][y] = 1;//��� �����ϵ� �Ϸ�� �� �� �ֱ� ������ 1��
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = di[i] + x;//�̵��� x��ǥ
		ny = dj[i] + y;//�̵��� y��ǥ
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {//���� ���� ��ǥ
			if (map[x][y] < map[nx][ny]) {
				dp[x][y] = max(dp[x][y], simulation(nx, ny) + 1);
			}
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k = max(k, simulation(i, j));
		}
	}
	cout << k << endl;
}