#include <iostream>
#include <queue>
using namespace std;

int boxes[100][100][100] = { 0, };
int dh[6] = { -1,1,0,0,0,0 };//�� �Ʒ�
int dx[6] = { 0,0,-1,1,0,0 };//��, ��
int dy[6] = { 0,0,0,0,-1,1 };//��, ��

int main() {
	int M, N, H;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> boxes[i][j][k];
			}
		}
	}
}