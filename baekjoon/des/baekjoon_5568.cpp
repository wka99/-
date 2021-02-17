#include <iostream>
#include <set>
#include <string>
using namespace std;

int n, k;
string cards[11];
int check[11];
set<string> comp;

void make(string cur, int sz) {
	if (sz == k) {
		comp.insert(cur);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			make(cur + cards[i], sz + 1);
			check[i] = 0;
		}
	}
}
int main() {
	string s;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cards[i] = s;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			make(cards[i], 1);
			check[i] = 0;
		}
	}
	cout << comp.size() << endl;
}