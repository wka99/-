#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000001
#define MAX_K 11

int K;
string s;
//���ڰ� x�̰� ���� ������ ������ y�϶� ���� �� �ִ� ���� ū ��
int dp[MAX_N][MAX_K];

int makeBig(string curr, int cnt) {
	int c_toi = stoi(curr);
	if (cnt == K) return c_toi;
	if (dp[c_toi][cnt] != 0) return dp[c_toi][cnt];
	string tmp = curr;
	int ret = -1;
	for (int i = 0; i < curr.size()-1; i++) {
		for (int j = i + 1; j < curr.size(); j++) {
			if (i == 0 && curr[j] == '0') continue;
			swap(tmp[i], tmp[j]);
			ret = max(ret, makeBig(tmp, cnt + 1));
			tmp = curr;
		}
	}
	return dp[c_toi][cnt] = ret;
}
int main() {
	cin >> s >> K;
	cout << makeBig(s, 0) << endl;
}