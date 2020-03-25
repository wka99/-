#include <iostream>
#include <algorithm>
using namespace std;

int T;
int n;
int sticker[2][100002] = { 0, };
int result[2][100002] = { 0, };

void init() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 100002; j++) {
			sticker[i][j] = 0;
			result[i][j] = 0;
		}
	}
}
int dp() {
	int maxR = 0;
	result[0][1] = sticker[0][1];
	result[1][1] = sticker[1][1];
	for (int j = 2; j < 100002; j++) {
		result[0][j] = max({ result[1][j - 1] + sticker[0][j], sticker[0][j] + result[0][j - 2], sticker[0][j]+result[1][j-2] });
		result[1][j] = max({ result[0][j - 1] + sticker[1][j], sticker[1][j] + result[1][j - 2], sticker[1][j] + result[0][j - 2] });
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 100002; j++) {
			if (maxR < result[i][j])maxR = result[i][j];
		}
	}
	return maxR;
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k < n+1; k++) {
				cin >> sticker[j][k];
			}
		}
		cout << dp() << endl;
		init();
	}
}