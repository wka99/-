#include <iostream>
#include <queue>
using namespace std;

class INFO {
public:
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};

int N, M;
char map[11][11];
INFO marble;

/*
	. => 后沫
	# => 厘局拱
	o => 备港
	R => 弧埃 备浇
	B => 颇鄂 备浇
*/
int play() {
	int visited[11][11][11][11] = { 0, };
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	int ans = -1;
	queue<INFO> q;
	q.push(marble);
	visited[marble.ry][marble.rx][marble.by][marble.bx] = 1;
	while (!q.empty()) {
		INFO cur = q.front();
		q.pop();
		if (cur.cnt > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ans = cur.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;
			while (1) {
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
					next_rx += dx[i]; next_ry += dy[i];
				}
				else {
					if (map[next_ry][next_rx] == '#') {
						next_rx -= dx[i]; next_ry -= dy[i];
					}
					break;
				}
			}
			while (1) {
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
					next_bx += dx[i]; next_by += dy[i];
				}
				else {
					if (map[next_by][next_bx] == '#') {
						next_bx -= dx[i]; next_by -= dy[i];
					}
					break;
				}
			}
			if (next_rx == next_bx && next_ry == next_by) {
				if (map[next_ry][next_rx] != 'O') {
					int red = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
					int blue = abs(next_bx - cur.bx) + abs(next_by - cur.by);
					if (red > blue) {
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
					else {
						next_bx -= dx[i];
						next_by -= dy[i];
					}
				}
			}
			if (!visited[next_ry][next_rx][next_by][next_bx]) {
				visited[next_ry][next_rx][next_by][next_bx] = 1;
				INFO next;
				next.rx = next_rx; next.ry = next_ry;
				next.bx = next_bx; next.by = next_by;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') {
				marble.ry = i; marble.rx = j;
			}
			else if (map[i][j] == 'B') {
				marble.by = i; marble.bx = j;
			}
		}
	}
	marble.cnt = 0;
	cout << play() << endl;
}