#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
int N;

char RGB[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int idx[4] = { -1,1,0,0 };//상, 하
int idy[4] = { 0,0,-1,1 };//좌, 우
queue <pair<int,int>> check;

void bfs(int a, int b) {
	check.push(make_pair(a, b));
	visited[a][b] = 1;
	int x, y;//현재 위치
	char rgb;//현재 rgb
	int mx, my;//이동 이후의 위치
	char mrgb; //이동한 곳의 rgb
	while (!check.empty()) {
		x = check.front().first;
		y = check.front().second;
		check.pop();
		rgb = RGB[x][y];
		for (int i = 0; i < 4; i++) {
			mx = x + idx[i];
			my = y + idy[i];
			if (mx >= 0 && mx < N&&my >= 0 && my < N&&visited[mx][my] == 0) {//범위 내&방문 여부 확인
				mrgb = RGB[mx][my];
				if (rgb == mrgb) {//일치하는 경우 추가
					check.push(make_pair(mx, my));
					visited[mx][my] = 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> RGB[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				count++;
			}
		}
	}
	int rgcount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
			if (RGB[i][j] == 'G')
				RGB[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				rgcount++;
			}
		}
	}
	cout << count <<" "<<rgcount<< "\n";
}