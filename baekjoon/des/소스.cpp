#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 21

int N;
vector<vector<int>> board(MAX_N, vector<int>(MAX_N, 0));
int ans = 0;

void UP(vector<vector<int>> board, vector<vector<int>>& ret) {
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = 0; j < N; j++) {
			if (board[j][i] == 0) continue;
			if (!flag) {
				tmp.push_back(board[j][i]);
				flag = 1;
			}
			else {
				int top = tmp[tmp.size() - 1];
				if (top == board[j][i]) {
					tmp.pop_back();
					tmp.push_back(board[j][i] + top);
					flag = 0;
				}
				else {
					tmp.push_back(board[j][i]);
				}
			}
		}
		int idx = 0;
		for (int j = 0; j < tmp.size(); j++) {
			ret[idx][i] = tmp[j]; idx++;
		}
	}
}
void DOWN(vector<vector<int>> board, vector<vector<int>>& ret) {
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = N-1; j >= 0; j--) {
			if (board[j][i] == 0) continue;
			if (!flag) {
				tmp.push_back(board[j][i]);
				flag = 1;
			}
			else {
				int top = tmp[tmp.size() - 1];
				if (top == board[j][i]) {
					tmp.pop_back();
					tmp.push_back(board[j][i] + top);
					flag = 0;
				}
				else {
					tmp.push_back(board[j][i]);
				}
			}
		}
		int idx = N - 1;
		for (int j = 0; j < tmp.size(); j++) {
			ret[idx][i] = tmp[j]; idx--;
		}
	}
}
void LEFT(vector<vector<int>> board, vector<vector<int>>& ret) {
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			if (!flag) {
				tmp.push_back(board[i][j]);
				flag = 1;
			}
			else {
				int top = tmp[tmp.size()-1];
				if (top == board[i][j]) {
					tmp.pop_back();
					tmp.push_back(board[i][j] + top);
					flag = 0;
				}
				else {
					tmp.push_back(board[i][j]);
				}
			}
		}
		int idx = 0;
		for (int j = 0; j < tmp.size(); j++) {
			ret[i][idx] = tmp[j]; idx++;
		}
	}
}
void RIGHT(vector<vector<int>> board, vector<vector<int>>& ret) {
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = N-1; j >=0; j--) {
			if (board[i][j] == 0) continue;
			if (!flag) {
				tmp.push_back(board[i][j]);
				flag = 1;
			}
			else {
				int top = tmp[tmp.size() - 1];
				if (top == board[i][j]) {
					tmp.pop_back();
					tmp.push_back(board[i][j] + top);
					flag = 0;
				}
				else {
					tmp.push_back(board[i][j]);
				}
			}
		}
		int idx = N - 1;
		for (int j = 0; j < tmp.size(); j++) {
			ret[i][idx] = tmp[j]; idx--;
		}
	}
}
void play(int cnt, vector<vector<int>> board) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> ret(MAX_N, vector<int>(MAX_N, 0));
		if (i == 0) UP(board, ret);
		else if (i == 1) DOWN(board, ret);
		else if (i == 2) LEFT(board, ret);
		else if (i == 3) RIGHT(board, ret);
		play(cnt + 1, ret);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	play(0, board);
	cout << ans << endl;
}