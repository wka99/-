#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 9
int map[MAX][MAX]; //������ ����
int tmp[MAX][MAX];
int dn[4] = { 1,-1,0,0 }; //��, ��
int dm[4] = { 0,0,-1,1 }; //��, ��
int n = 0, m = 0; //���� ũ��, ���� ũ��
queue<pair<int, int>> virus; //���̷��� ��ġ
int maxSafeZone = 0; //�ִ� ���� ���� ũ��

void BFS() { //���̷����� BFS�� ������� ��������
	queue<pair<int, int>> tv = virus;
	int final[MAX][MAX];
	memcpy(final, tmp, sizeof(tmp));
	int v_n = 0, v_m = 0; //���̷��� ����,���� ��ǥ
	int v_n_m = 0, v_m_m = 0; //���̷��� �̵� ��ǥ
	int safe = 0; //���� ���� ���� ũ��
	while (!tv.empty()) {
		v_n = tv.front().first;
		v_m = tv.front().second;
		tv.pop();
		for (int i = 0; i < 4; i++) {
			v_n_m = v_n + dn[i];
			v_m_m = v_m + dm[i];
			if (v_n_m >= 0 && v_n_m < n && v_m_m >= 0 && v_m_m < m && final[v_n_m][v_m_m] == 0) {
				//���� ���� ��ġ & ������� ��� ������Ŵ
				final[v_n_m][v_m_m] = 2;
				tv.push({ v_n_m,v_m_m }); //�� ���̷����� ��ġ ����
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (final[i][j] == 0)
				safe++;
		}
	}
	if (maxSafeZone < safe)
		maxSafeZone = safe;
}

void makeWall(int count) { //��ͷ� ��� ����� �� ����
	if (count == 3) { //���� ���� ��� ���� ���
		BFS(); //���̷����� ������ ���� ���� ������ ũ�� ���
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				makeWall(count + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m; //���� ũ��, ���� ũ�� �Է¹ޱ�
	for (int i = 0; i < n; i++) { //������ ���� �Է¹ޱ�
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) { //���̷��� ��ġ �Է�
				virus.push({ i,j });
			}
		}
	}
	//���Ʈ ������ ��� ����� ���� ���� ����� ���� �� �ִ� ���� ������ �ִ� ũ�⸦ ���

	for (int i = 0; i < n; i++) { //������ ���� Ž��
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { //����ִ� ������ ���� ����
				memcpy(tmp, map, sizeof(map)); //tmp�� ���� ������ ���� ����
				tmp[i][j] = 1; //���� ����
				makeWall(1);
			}
		}
	}
	cout << maxSafeZone << endl;
}