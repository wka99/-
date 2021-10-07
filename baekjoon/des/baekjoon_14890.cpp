#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int N, L;
int map[MAX][MAX];
int ans = 0;

void checkRow(int x) {
	int curr = map[x][0];
	int cnt = 0;
	vector <pair<int, int>> heights;
	for (int i = 0; i < N; i++) {
		if (curr == map[x][i])cnt++;
		else {
			heights.push_back({ curr, cnt });
			curr = map[x][i];
			cnt = 1;
		}
	}
	if (cnt) heights.push_back({ curr, cnt });
	for (int i = 0; i < heights.size() - 1; i++) {
		int currh = heights[i].first;
		int currc = heights[i].second;
		int nexth = heights[i + 1].first;
		int nextc = heights[i + 1].second;
		if (currh < nexth) { //올라가는 경사로
			if (currc < L || nexth - currh > 1) return;//경사로를 놓을 자리가 없거나 높이 차이가 1이상
			else heights[i].second -= L; //경사로를 놓음

		}
		else if (currh > nexth) { //내려가는 경사로
			if (nextc < L || currh - nexth > 1) return;
			else heights[i + 1].second -= L;
		}
	}
	ans++;
}
void checkCol(int x) {
	int curr = map[0][x];
	int cnt = 0;
	vector <pair<int, int>> heights;
	for (int i = 0; i < N; i++) {
		if (curr == map[i][x])cnt++;
		else {
			heights.push_back({ curr, cnt });
			curr = map[i][x];
			cnt = 1;
		}
	}
	if (cnt) heights.push_back({ curr, cnt });
	for (int i = 0; i < heights.size() - 1; i++) {
		int currh = heights[i].first;
		int currc = heights[i].second;
		int nexth = heights[i + 1].first;
		int nextc = heights[i + 1].second;
		if (currh < nexth) {
			if (currc < L || nexth - currh > 1) return;
			else heights[i].second -= L;

		}
		else if (currh > nexth) {
			if (nextc < L || currh - nexth > 1) return;
			else heights[i + 1].second -= L;
		}
	}
	ans++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		checkRow(i);
		checkCol(i);
	}
	cout << ans << endl;
}