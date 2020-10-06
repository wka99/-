#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int flag = 0;
	while (!flag) {
		flag = 1;
		int visited[30][30] = { 0, };
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] == 0) continue;
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
					visited[i][j] = 1;
					visited[i][j + 1] = 1;
					visited[i + 1][j] = 1;
					visited[i + 1][j + 1] = 1;
					flag = 0;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 1) { //노드 삭제
					answer++;
					for (int k = i - 1; k >= 0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	cout<<solution(6, 6, board);
}