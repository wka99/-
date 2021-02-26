#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100001

//���û����� ��� ������ ���� ��� �ּ��� ���� ���϶�
int dp[5][5][MAX];//dp[x][y][i], i��° ���û���, �� ��ġ ���� x, y;
vector<int> cmd; //���� ����

int power(int curr, int prev) {
	if (prev == 0) return 2;
	if (curr == prev) return 1;
	if (abs(curr - prev) == 2) return 4;
	if (abs(curr - prev) == 1) return 3;
}
int move(int a, int b, int idx) {
	if (idx == cmd.size()) return 0;
	if (dp[a][b][idx] != -1) return dp[a][b][idx];
	int left = move(cmd[idx], b, idx + 1) + power(cmd[idx], a);
	int right = move(a, cmd[idx], idx + 1) + power(cmd[idx], b);
	dp[a][b][idx] = min(left, right);
	return dp[a][b][idx];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int c;
	while (1) {
		cin >> c;
		if (c == 0) break;
		cmd.push_back(c);
	}
	memset(dp, -1, sizeof(dp));
	cout << move(0, 0, 0) << endl; //�ʱ� ����ġ
}