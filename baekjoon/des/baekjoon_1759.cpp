#include <iostream>
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
}