#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
char alpha[16];
int visited[16];
//최소 1개의 모음, 최소 2개의 자음으로 구성
//암호는 알파벳이 증가하는 순서

void makeCipher(int idx, int cons, int vow, string s) {
	if (idx == L) {
		if (cons > 1 && vow > 0)
			cout << s << "\n";
		return;
	}
	for (int i = 0; i < C; i++) {
		if (!visited[i] && (idx == 0 || s[idx-1] < alpha[i])) {
			if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
				visited[i] = 1;
				makeCipher(idx + 1, cons, vow + 1, s + alpha[i]);
				visited[i] = 0;
			}
			else {
				visited[i] = 1;
				makeCipher(idx + 1, cons + 1, vow, s + alpha[i]);
				visited[i] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha, alpha + C);
	makeCipher(0, 0, 0, "");
}