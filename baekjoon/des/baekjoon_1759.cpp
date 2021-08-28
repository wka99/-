#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <char> chars;
int L, C;

void makeCipher(string cipher, int idx, int c, int v) {
	if (cipher.length() == L) {
		if (v >= 1 && c >= 2)
			cout << cipher << "\n";
		return;
	}
	if (idx == chars.size())return;
	int flag = 0;//0:자음 1:모음
	if (chars[idx] == 'a' || chars[idx] == 'e' || chars[idx] == 'i' || chars[idx] == 'o' || chars[idx] == 'u')
		flag = 1;
	if (flag) {
		makeCipher(cipher + chars[idx], idx + 1, c, v + 1);
		makeCipher(cipher, idx + 1, c, v);
	}
	else {
		makeCipher(cipher + chars[idx], idx + 1, c + 1, v);
		makeCipher(cipher, idx + 1, c, v);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		chars.push_back(c);
		sort(chars.begin(), chars.end());
	}
	makeCipher("", 0, 0, 0);
}
/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alpha;
int check[26] = { 0, };
int v, c;
vector<string> ans;

void makeCode(int idx, int cv, int cc, string s) {
	if (s.size() == L) {
		ans.push_back(s);
		return;
	}
	for (int i = idx; i < alpha.size(); i++) {
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
			if (cv < v) {
				if (!check[alpha[i] - 'a']) {
					check[alpha[i] - 'a'] = 1;
					makeCode(i + 1, cv + 1, cc, s + alpha[i]);
					check[alpha[i] - 'a'] = 0;
				}
			}
			else continue;
		}
		else {
			if (cc < c) {
				if (!check[alpha[i] - 'a']) {
					check[alpha[i] - 'a'] = 1;
					makeCode(i + 1, cv, cc + 1, s + alpha[i]);
					check[alpha[i] - 'a'] = 0;
				}
			}
			else continue;
		}
	}
}
int main() {
	char tmp;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> tmp;
		alpha.push_back(tmp);
	}
	sort(alpha.begin(), alpha.end());
	v = 1;
	c = L - v;
	while (1) {
		if (c < 2) break;
		if (v > 5) break;
		makeCode(0, 0, 0, "");
		v++;
		c--;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}*/
