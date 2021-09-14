#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 11

class INFO {
public:
	int rx, ry, bx, by;
	int cnt = 0;
};

int N, M;
INFO start;
char map[MAX_N][MAX_N];
//빨간 구슬, 파란 구슬의 위치가 모두 같은 경우, 같은 이동 방법만 나오게 된다.
int visited[MAX_N][MAX_N][MAX_N][MAX_N];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int play() {
	int ans = -1;
	queue <INFO> q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = 1;
	while (!q.empty()) {
		INFO curr = q.front(); q.pop();
		if (curr.cnt > 10) break;
		if (map[curr.rx][curr.ry] == 'O' && map[curr.bx][curr.by] != 'O') {
			ans = curr.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_rx = curr.rx;
			int next_ry = curr.ry;
			int next_bx = curr.bx;
			int next_by = curr.by;
			while (map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O') {
				next_rx += dx[i];
				next_ry += dy[i];
			}
			if (map[next_rx][next_ry] == '#') {
				next_rx -= dx[i];
				next_ry -= dy[i];
			}
			while (map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O') {
				next_bx += dx[i];
				next_by += dy[i];
			}
			if (map[next_bx][next_by] == '#') {
				next_bx -= dx[i];
				next_by -= dy[i];
			}
			if (next_rx == next_bx && next_ry == next_by) {
				if (map[next_rx][next_ry] != 'O') {
					int red = abs(next_rx - curr.rx) + abs(next_ry - curr.ry);
					int blue = abs(next_bx - curr.bx) + abs(next_by - curr.by);
					if (blue > red) {
						next_bx -= dx[i];
						next_by -= dy[i];
					}
					else {
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
				}
			}
			if (visited[next_rx][next_ry][next_bx][next_by]) continue;
			visited[next_rx][next_ry][next_bx][next_by] = 1;
			INFO next;
			next.rx = next_rx; next.ry = next_ry;
			next.bx = next_bx; next.by = next_by;
			next.cnt = curr.cnt + 1;
			q.push(next);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				start.rx = i; start.ry = j;
			}
			else if (map[i][j] == 'B') {
				start.bx = i; start.by = j;
			}
		}
	}
	cout << play() << endl;
}