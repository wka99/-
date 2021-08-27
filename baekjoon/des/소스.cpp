#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
#define MAX_K 11

string N;
int K;
int dp[MAX_N][MAX_K];

int makeBig(string curr, int cnt) {
	int ctoi = stoi(curr);
	if (cnt == 0) return ctoi;
	if (dp[ctoi][cnt]) return dp[ctoi][cnt];
	int ret = -1;
	string tmp = curr;
	for (int i = 0; i < tmp.length() - 1; i++) {
		for (int j = i + 1; j < tmp.length(); j++) {
			if (i==0 && tmp[j] == '0') continue;
			swap(tmp[i], tmp[j]);
			ret = max(ret, makeBig(tmp, cnt - 1));
			tmp = curr;
		}
	}
	return dp[ctoi][cnt] = ret;
}
int main() {
	cin >> N >> K;
	cout<<makeBig(N, K);
}