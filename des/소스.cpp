#include <iostream>
using namespace std;

int n = 0;//대나무 숲 크기
int map[500][500] = { 0, };//대나무 숲 지도
int di[4] = { 1,-1,0,0, };//상, 하
int dj[4] = { 0,0,-1,1 };//좌, 우
int dp[500][500] = { 0, };//각 위치에서 시작했을 때 판다가 살 수 있는 일수를 저장
int k = 0;//판다가 최대한 살 수 있는 일수

int max(int a, int b) { return a > b ? a : b; }//더 큰값 반환

int simulation(int x, int y) {
	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	dp[x][y] = 1;//어디서 시작하든 하루는 살 수 있기 때문에 1로
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = di[i] + x;//이동후 x좌표
		ny = dj[i] + y;//이동후 y좌표
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {//범위 안의 좌표
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