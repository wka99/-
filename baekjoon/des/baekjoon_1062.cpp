#include <iostream>
#include <string>
#include <map>
using namespace std;
#define MAX_N 51

int N, K;
string words[MAX_N];
map <char, int> should;
//a n t i c 은 반드시 알아야함
int maxV = 0;

void learn(int cnt) {
	if (cnt == K) {
		int ans = 0, i, j;
		for (i = 0; i < N; i++) {
			for (j = 0; j < words[i].size(); j++) {
				if (should[words[i][j]] == 0) break;
			}
			if (j == words[i].size()) ans++;
		}
		maxV = max(maxV, ans);
		return;
	}
	char f = 'a', next;
	for (int i = 0; i < 26; i++) {
		next = f + i;
		if (should.find(next) == should.end()) continue;
		if (!should[next]) {
			should[next] = 1;
			learn(cnt + 1);
			should[next] = 0;
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		for (int j = 0; j < words[i].size(); j++) {
			should[words[i][j]] = 0;
		}
	}
	should['a'] = 1; should['n'] = 1;
	should['t'] = 1; should['i'] = 1; should['c'] = 1;
	if (K < 5) cout << 0 << endl;
	else {
		learn(5);
		cout << maxV << endl;
	}
}