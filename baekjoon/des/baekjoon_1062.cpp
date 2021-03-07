#include <iostream>
#include <string>
using namespace std;
#define MAX_N 51
#define anum 'a'

int N, K;
string words[MAX_N];
int alpha[26];
//a n t i c 은 반드시 알아야함
int maxV = 0;

void learn(int idx, int cnt) {
	if (cnt == K) {
		int ans = 0, curr, len;
		for (int i = 0; i < N; i++) {
			curr = 0; len = words[i].size();
			for (int j = 0; j < len; j++) {
				if (alpha[words[i][j] - anum]) curr++;
			}
			if (curr == len) ans++;
		}
		maxV = max(maxV, ans);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = 1;
			learn(i + 1, cnt + 1);
			alpha[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
	if (K < 5) cout << 0 << endl;
	else {
		alpha['a' - anum] = 1;
		alpha['n' - anum] = 1;
		alpha['t' - anum] = 1;
		alpha['i' - anum] = 1;
		alpha['c' - anum] = 1;
		K -= 5;
		learn(0,0);
		cout << maxV << endl;
	}
}