#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;

void Check(int x, int y, int size, vector<int>& ans) {
	bool zero = true, one = true;
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] == 0) one = false;
			if (map[i][j] == 1) zero = false;
		}
	}
	if (zero == true) {
		ans[0]++;
		return;
	}
	else if (one == true) {
		ans[1]++;
		return;
	}
	Check(x, y, size / 2, ans);
	Check(x, y + size / 2, size / 2, ans);
	Check(x + size / 2, y, size / 2, ans);
	Check(x + size / 2, y + size / 2, size / 2, ans);
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2,0);
	map = arr;
	Check(0, 0, arr.size(), answer);
	cout << answer[0] << " " << answer[1] << endl;
	return answer;
}
int main() {
	solution({ {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1} });
}