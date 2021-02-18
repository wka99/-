#include <iostream>
#include <string>
using namespace std;
#define MAX 4001

string a, b;
int dp[MAX][MAX];
int maxV = 0;
int main() {
	cin >> a >> b;
	if (a.length() > b.length()) swap(a, b);
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (maxV < dp[i][j]) maxV = dp[i][j];
			}
			//else에 대해서는 고려할 필요가 없다
			//부분 문자열은 연속되어야 하는 특성이 있기 때문에 중간에 끊기면 의미가 없음
			//또한, a[i-1]과 b[i-1]이 같아야 기존의 최장 부분 문자열의 길이가 늘어나는 것
		}
	}
	cout << maxV << endl;
}