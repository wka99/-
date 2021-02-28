#include <iostream>
using namespace std;

int chess[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	char c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'W') chess[i][j] = 1;
			else chess[i][j] = 0;
		}
	}
	int minV = 2501;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for (int k = 0; k < 2; k++) { //맨위의 색 결정
				int curr = k;
				int cnt = 0;
				for (int a = i; a < i + 8; a++) {
					for (int b = j; b < j + 8; b++) {
						if (curr != chess[a][b]) cnt++;
						if(b != j+7) curr = !curr;
					}
				}
				minV = min(minV, cnt);
			}
		}
	}
	cout << minV << "\n";
}