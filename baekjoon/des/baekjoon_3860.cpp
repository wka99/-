#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 31
#define INF 987654321

int W, H, G, E;
int grave[MAX][MAX];
long long dist[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<long long>> edges; //x1, y1, x2, y2, t

//������ ���������µ� �ɸ��� ���� ���� �ð�
//�� ��ǥ�� �ϳ��� ���� ���� ���� ����

void bellman() {
	long long x1, y1, x2, y2, t;
	int nodes = W * H - G;
	for (int i = 1; i <= nodes; i++) {
		for (int j = 0; j < edges.size(); j++) {
			x1 = edges[j][0]; y1 = edges[j][1];
			x2 = edges[j][2]; y2 = edges[j][3];
			t = edges[j][4];
			if (dist[x1][y1] == INF) continue;
			if (dist[x2][y2] > dist[x1][y1] + t) {
				if (i == nodes) {
					cout << "Never\n";
					return;
				}
				else dist[x2][y2] = dist[x1][y1] + t;
			}
		}
	}
	if (dist[W - 1][H - 1] == INF) cout << "Impossible\n";
	else cout << dist[W - 1][H - 1] << "\n";
}
void init() {
	edges.clear();
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			grave[i][j] = 0;
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long  x1, y1, x2, y2, t;
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		cin >> G;
		init();
		for (int i = 0; i < G; i++) {//���� ǥ��
			cin >> x1 >> y1;
			grave[x1][y1] = 1;
		}
		cin >> E;
		for (int i = 0; i < E; i++) { //�ͽ� ���� ǥ��
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			grave[x1][y1] = 2;
			edges.push_back({ x1,y1,x2,y2,t });
		}
		//���� ����
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < H; j++) {
				if (grave[i][j]) continue; //�ͽ� ���۰� ���������� ������� ������ �� ����
				if (i == W - 1 && j == H - 1) continue;
				for (int k = 0; k < 4; k++) {
					int mx = i + dx[k];
					int my = j + dy[k];
					if (mx < 0 || my < 0 || mx >= W || my >= H) continue;
					if (grave[mx][my] == 1) continue;
					edges.push_back({ i, j, mx, my, 1 });
				}
			}
		}
		bellman();
	}
}