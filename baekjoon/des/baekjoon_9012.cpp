#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, i, j;
	string s;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> s;
		int open = 0;
		for (j = 0; j < s.size(); j++) {
			if (s[j] == '(') open++;
			else {
				if (open > 0)open--;
				else {
					cout << "NO\n";
					break;
				}
			}
		}
		if (j == s.size()) {
			if (open != 0) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}