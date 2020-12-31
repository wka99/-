#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 1234;
	int mine, maxe = 0;
	vector<vector<int>> cpy = board;
	if (board.size() == 1 && board[0].size() == 1 && board[0][0] == 1) {
		return 1;
	}
	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			if (board[i][j] >= 1) {
				mine = min(board[i - 1][j], min(board[i - 1][j - 1], board[i][j - 1]));
				board[i][j] = mine + 1;
				if (maxe < board[i][j])
					maxe = board[i][j];
			}
		}
	}
	answer = maxe * maxe;
	return answer;
}