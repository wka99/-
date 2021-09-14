#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;
int maxV = 0;

/*
	최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
	1. 같은 값을 가지는 두 블록이 충돌하면 하나로 합쳐짐
	2. 이미 합쳐진 블록은 다른 블록과 합쳐질 수 없음
*/

vector<vector<int>> UP(vector<vector<int>> curr) {
	vector<vector<int>> ret(N, (vector<int>(N, 0)));
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = 0; j < N; j++) {
			if (curr[j][i] == 0) continue;
			if (!tmp.empty()) {
				if (!flag && tmp[tmp.size() - 1] == curr[j][i]) {
					tmp[tmp.size() - 1] += curr[j][i];
					flag = 1;
				}
				else {
					tmp.push_back(curr[j][i]);
					flag = 0;
				}
			}
			else {
				tmp.push_back(curr[j][i]);
				flag = 0;
			}
		}
		for (int j = 0; j < tmp.size(); j++)
			ret[j][i] = tmp[j];
	}
	return ret;
}
vector<vector<int>> DOWN(vector<vector<int>> curr) {
	vector<vector<int>> ret(N, (vector<int>(N, 0)));
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (curr[j][i] == 0) continue;
			if (!tmp.empty()) {
				if (!flag && tmp[tmp.size() - 1] == curr[j][i]) {
					tmp[tmp.size() - 1] += curr[j][i];
					flag = 1;
				}
				else {
					tmp.push_back(curr[j][i]);
					flag = 0;
				}
			}
			else {
				tmp.push_back(curr[j][i]);
				flag = 0;
			}
		}
		for (int j = 0; j < tmp.size(); j++)
			ret[N - j - 1][i] = tmp[j];
	}
	return ret;
}
vector<vector<int>> LEFT(vector<vector<int>> curr) {
	vector<vector<int>> ret(N, (vector<int>(N, 0)));
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = 0; j < N; j++) {
			if (curr[i][j] == 0) continue;
			if (!tmp.empty()) {
				if (!flag && tmp[tmp.size() - 1] == curr[i][j]) {
					tmp[tmp.size() - 1] += curr[i][j];
					flag = 1;
				}
				else {
					tmp.push_back(curr[i][j]);
					flag = 0;
				}
			}
			else {
				tmp.push_back(curr[i][j]);
				flag = 0;
			}
		}
		for (int j = 0; j < tmp.size(); j++)
			ret[i][j] = tmp[j];
	}
	return ret;
}
vector<vector<int>> RIGHT(vector<vector<int>> curr) {
	vector<vector<int>> ret(N, (vector<int>(N, 0)));
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int flag = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (curr[i][j] == 0) continue;
			if (!tmp.empty()) {
				if (!flag && tmp[tmp.size() - 1] == curr[i][j]) {
					tmp[tmp.size() - 1] += curr[i][j];
					flag = 1;
				}
				else {
					tmp.push_back(curr[i][j]);
					flag = 0;
				}
			}
			else {
				tmp.push_back(curr[i][j]);
				flag = 0;
			}
		}
		for (int j = 0; j < tmp.size(); j++)
			ret[i][N - j - 1] = tmp[j];
	}
	return ret;
}
void play(int cnt, vector<vector<int>> curr) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxV = max(maxV, curr[i][j]);
			}
		}
		return;
	}
	play(cnt + 1, UP(curr));
	play(cnt + 1, DOWN(curr));
	play(cnt + 1, LEFT(curr));
	play(cnt + 1, RIGHT(curr));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		board.push_back(tmp);
	}
	play(0, board);
	cout << maxV << endl;
}