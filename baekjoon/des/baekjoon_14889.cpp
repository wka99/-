#include <iostream>
using namespace std;
#define MAX 21

int N;
int point[MAX][MAX];
int visited[MAX];
int ans = 2001;
//스타트 팀과 링크 팀의 능력치의 차이의 최솟값

void makeTeam(int idx, int cnt) {
	if (cnt == N / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i == j) continue;
				if (visited[i] && visited[j]) {
					start += point[i][j];
					start += point[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					link += point[i][j];
					link += point[j][i];
				}
			}
		}
		ans = min(ans, abs(start - link));
		return;
	}
	if (idx == N) return;
	visited[idx] = 1;
	makeTeam(idx + 1, cnt + 1);
	visited[idx] = 0;
	makeTeam(idx + 1, cnt);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> point[i][j];
		}
	}
	makeTeam(0, 0);
	cout << ans << endl;
}