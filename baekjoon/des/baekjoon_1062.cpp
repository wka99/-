#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
int alpha[26];
vector<string> words;
int ans = 0;

//a c i n t 는 반드시 알고 있어야 함

void learn(int idx, int cnt) {
	if (cnt == K) {
		int i, j;
		int cnt = 0;
		for (i = 0; i < words.size(); i++) {
			for (j = 0; j < words[i].length(); j++) {
				if (!alpha[words[i][j] - 'a']) break;
			}
			if (j == words[i].length()) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}
	if (idx == 26) return;
	if (alpha[idx]) {
		learn(idx + 1, cnt);
		return;
	}
	alpha[idx] = 1;
	learn(idx + 1, cnt + 1);
	alpha[idx] = 0;
	learn(idx + 1, cnt);
}
int main() {
	string tmp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		words.push_back(tmp);
	}
	K -= 5;
	if (K < 0) cout << 0 << endl;
	else {
		alpha['a' - 'a'] = 1;
		alpha['c' - 'a'] = 1;
		alpha['i' - 'a'] = 1;
		alpha['n' - 'a'] = 1;
		alpha['t' - 'a'] = 1;
		learn(0, 0);
		cout << ans << endl;
	}
}