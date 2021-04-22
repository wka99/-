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
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 9

int N, M;
vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> vacant;
queue<pair<int, int>> virus;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

void spread(vector<vector<int>> board) {
	int x, y, mx, my;
	queue<pair<int, int>> t_virus = virus;
	while (!t_virus.empty()) {
		int x = t_virus.front().first;
		int y = t_virus.front().second;
		t_virus.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx < 0 || mx >= N || my < 0 || my >= M) continue;
			if (board[mx][my] != 0)continue;
			board[mx][my] = 2;
			t_virus.push({ mx, my });
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)ret++;
		}
	}
	ans = max(ans, ret);
}
void makeWall(int idx, int cnt, vector<vector<int>> board) {
	if (cnt == 3) {
		spread(board);
		return;
	}
	if (idx == vacant.size()) return;
	int x = vacant[idx].first;
	int y = vacant[idx].second;
	board[x][y] = 1;
	makeWall(idx + 1, cnt + 1, board);
	board[x][y] = 0;
	makeWall(idx + 1, cnt, board);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) vacant.push_back({ i,j });
			if (board[i][j] == 2) virus.push({ i,j });
		}
	}
	makeWall(0, 0, board);
	cout << ans << endl;
}
*/