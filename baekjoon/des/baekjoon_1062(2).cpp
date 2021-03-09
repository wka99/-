#include <iostream>
#include <string>
using namespace std;

int N, K;
int words[51];
int learn = 0, maxV = 0;

void teach(int idx, int cnt) {
	if (cnt == K) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if ((words[i] & learn) == words[i]) ret++;
		}
		maxV = max(maxV, ret);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if ((learn & 1 << i) == 0) {
			learn = learn | 1 << i; //on
			teach(i + 1, cnt + 1);
			learn = learn & ~(1 << i); //off
		}
	}
}
int main() {
	string s;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			words[i] |= 1 << s[j] - 'a'; //각 단어를 만들기 위해 필요한 알파벳 체크
		}
	}
	if (K < 5) {
		cout << 0 << endl;
	}
	else {
		learn |= 1 << 'a' - 'a';
		learn |= 1 << 'n' - 'a';
		learn |= 1 << 't' - 'a';
		learn |= 1 << 'i' - 'a';
		learn |= 1 << 'c' - 'a';
		K -= 5;
		teach(0, 0);
		cout << maxV << endl;
	}
}